from socket import *
import time

# 소켓을 생성하는 함수 
# 목적지 호스트의 ip주소, 포트 번호, 시작시간을 전역 변수에 저장하고
# 주어진 조건(IPv4, UDP소켓,응답시간1초) 에 맞는 소켓을 생성해 반환한다. 
def socket_create():
    global server_name
    global server_port
    server_name = "1.225.97.204"
    server_port = 12000

    clientSocket = socket(AF_INET,SOCK_DGRAM)
    clientSocket.settimeout(1)
    return clientSocket

# 소켓을 닫는 함수. 
# 소켓을 닫으며 프로세스가 종료된다.
def socket_close(clientSocket):
    print("End...")
    clientSocket.close()

# 메세지를 보내는 함수.
# 전달할 메세지를 입력받아 UDP 형식으로 메세지를 서버로 보낸다. 
def socket_send(clientSocket,sequence_number):
    global start_time

    message = input(str(sequence_number) + "번째 메세지 입력 >>")
    start_time = time.time()
    clientSocket.sendto(message.encode(), (server_name, server_port))

#총 경과시간(RTT)을 반환하는 함수
def RTT(start_time):
    return time.time() - start_time

# 서버로부터 패킷을 받는 함수. 
# 응답시간이 1초가 넘어가는 경우 예외처리한다.
# 수신받은 패킷 데이터와 소스 주소를 각 변수에 할당받고 RTT를 계산하여 출력한다.  
# 수신 받은 메세지는 인코드 되어있기 때문에 출력할 때 디코드를 한다.
def socket_receive(clientSocket,sequence_number):
    global start_time
    try: 
        modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
        print("num: ",sequence_number)
        print("message: " + modifiedMessage.decode())
        print("RTT: ", '%f' % RTT(start_time))
    except timeout:
        print("timed out!!")
    print("")

# 프로그램이 동작하는 메인함수
# create -> send -> receive -> close의 절차로 진행된다.
if __name__ == "__main__":
    clientSocket = socket_create()
    for sequence_number in range(1,11):
        socket_send(clientSocket,sequence_number)
        socket_receive(clientSocket,sequence_number)
    
    socket_close(clientSocket)
