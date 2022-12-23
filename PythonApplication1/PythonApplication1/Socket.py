import threading
import socket

HOST = socket.gethostbyname(socket.gethostname())
PORT = 8080

SERVER = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    SERVER.bind((HOST,PORT))
    print(f'* Running on http://{HOST}:{PORT}')
except socket.error as e:
    print("Socket creation error: " + str(e))

def _start():
    SERVER.listen()
    while True:
        conn, addr = SERVER.accept()
        thread = threading.Thread(target=_handle, args=(conn, addr))
        thread.start()



def _handle(conn, addr):
    while True:
        data = conn.recv(1024).decode()
        print("Client:", addr, "da ket noi den server")
        print(conn)
        print(data)
        if not data: 
            break
        request_line = data.split('\r\n')[0]
        request_method = request_line.split(' ')[0]
        reuqest_url = (request_line.split(' ')[1]).strip('/')
        print(request_method, reuqest_url)
        if request_method == 'GET':
            if reuqest_url == '':
                #index page
                url = 'index.html'
                Content_type = 'text/html'
            elif  reuqest_url.endswith('.ico'): 
                url = reuqest_url
                Content_type = 'image/x-icon'
            elif  reuqest_url.endswith('.html'):
                url = reuqest_url
                Content_type = 'text/html'
            #css file
            elif reuqest_url.endswith('.css'):
                url = reuqest_url
                Content_type = 'text/css'
            #image file
            elif reuqest_url.endswith('.png'):
                url = reuqest_url
                Content_type = 'image/png'
            elif reuqest_url.endswith('.jpg'):
                url = reuqest_url
                Content_type = 'image/jpg'

         #post file images.html
        elif "uname=admin&psw=123456" in data: 
            if request_method == 'POST':
                if  reuqest_url.endswith('.html'):
                    url = reuqest_url
                    Content_type = 'text/html'
                #css file
                elif reuqest_url.endswith('.css'):
                    url = reuqest_url
                    Content_type = 'text/css'
                elif reuqest_url.endswith('.jpg'):
                    url = reuqest_url
                    Content_type = 'image/jpg'
                elif reuqest_url.endswith('.png'):
                    url = reuqest_url
                    Content_type = 'image/png'
        else:
                    url = '401.html'
                    Content_type = 'text/html'
        data = _read_file(url, Content_type)
        conn.send(data)
        conn.close()
        break   
    



def _read_file(url, Content_type):
    try:
        with open(url, 'rb') as f:
            data = f.read()
    except:
        with open('404.html', 'rb') as f:
            url = '404.html'
            data = f.read()
            Content_type = 'text/html'
    if url == '404.html': 
        message_header = _response_header404(Content_type)
    elif url == '401.html': 
        message_header = _response_header401(Content_type)
    else:
        message_header = _response_header(Content_type)
    data = message_header + data
    return data

def _response_header(Content_type):
    header = 'HTTP/1.1 200 OK\r\n '
    header += 'Content-Type: ' + Content_type + '\r\n'
    header += 'Connection: close\r\n'
    header += '\r\n'
    #content file
    return header.encode()

def _response_header404(Content_type):
    header = 'HTTP/1.1 404 Not Found\r\n '
    header += 'Content-Type: ' + Content_type + '\r\n'
    header += 'Connection: close\r\n'
    header += '\r\n'
    return header.encode()


def _response_header401(Content_type):
    header = 'HTTP/1.1 401 Unauthorized\r\n '
    header += 'Content-Type: ' + Content_type + '\r\n'
    header += 'Connection: close\r\n'
    header += '\r\n'
    return header.encode()


if __name__ == '__main__':
    _start()