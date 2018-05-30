from socket import *
from sys import argv

def main():
  # Parse command line args
  if len(argv) != 3 or not argv[2].isdigit():
    print("usage: python3 client.py <server name> <server port>")
    return 1

  hostname, serverTCPPort = argv[1], int(argv[2])
  print("Client is running...")
  print("Remote host: {}, remote TCP port: {}".format(hostname, serverTCPPort))
 
  # Prompt user for their name
  # Create TCP socket
  clientSocket = socket(AF_INET,SOCK_STREAM)
  # Get IP address of server via DNS and print it(optional)

  # Connect to the server program
  clientSocket.connect((hostname,serverTCPPort))

  # Send hello message to the server over TCP connection
  hello = "hello "
  
  username = input("Enter your username: ")
  print("Sending hello message to server and setting username.. ")
  hello = hello + username
  clientSocket.sendto(hello.encode('utf-8'), (hostname, serverTCPPort))
  

  # TCP Loop
  while True:
    # Read in from TCP port
    uSock = clientSocket.recv(1024)
    # Keep listening if it doesn't receive a gameport message
    # Read the control message from the TCP socket and print its contents
    print("Received the UDP socket... ", uSock.decode('utf-8'))
    uSock = int(uSock.decode('utf-8'))
    break
    # Break from loop once needed info is received

  

  # Create a UDP socket
  udpSocket = socket(AF_INET, SOCK_DGRAM)
  serverInfo = (hostname, uSock)



  end = False # default end flag

  # Game loop
  while True:
    # Prompt

    valid_commands = ['start', 'end', 'guess', 'exit']
    print("Valid commands for the server are start, end, exit, and guess")
    action = input("What would you like to do?\n")
    try:
      if(action == 'start'):
        udpSocket.sendto(action.encode('utf-8'),serverInfo)
        print("Action: ", action)
        action = action.split()
      elif(action.split()[0] == 'guess'):
        udpSocket.sendto(action.encode('utf-8'),serverInfo)
        print("Action: ", action)
        action = action.split()
      elif(action.split()[0] =='end'):
        udpSocket.sendto(action.encode('utf-8'),serverInfo)
        print("Action: ", action)
        action = action.split()
      elif(action.split()[0] == 'exit'):
        udpSocket.sendto(action.encode('utf-8'),serverInfo)
        print("Action: ", action)
        action = action.split()
        break
      else:
        print("Incorrect action! Please enter one of the commands above!")
        error = 1
    except:
        print("Please entor the correct command!")
        error = 1

    
    
    # UDP loop
    while True:
      try:
        if(error == 1):
          break
      except:
        print("Waiting data from server...")
      # Continuously Read in from UDP port


      valid_msg_types = ["instr", "stat", "end", "na", "bye"]


      # print message

      # Instruction message should be followed by stat message
      
      if(action[0] == 'start'):
        
          instructions,addr = udpSocket.recvfrom(1024)
          instructions = instructions.decode('utf-8')
          print (instructions)
          attempts,addr = udpSocket.recvfrom(1024)
          word,addr = udpSocket.recvfrom(1024)
          word = word.decode('utf-8')
          print ("Number of attempts: ", attempts.decode('utf-8'))
          break
        
      if(action[0] == 'guess'):
        
        na,addr= udpSocket.recvfrom(1024)
        na = na.decode('utf-8')
        print(na)
        if(na == 'Active'):
          word_blanks,addr = udpSocket.recvfrom(1024)
          word_blanks = word_blanks.decode('utf-8')
          
          attempts,addr = udpSocket.recvfrom(1024)
          attempts = attempts.decode('utf-8')
          
          win,addr = udpSocket.recvfrom(1024)
          win = win.decode('utf-8')
          print("Win Status: ", win)
          if(int(attempts) == 0):
            print("You lost! Word was ", word)
          else:
            print("Guess the word: ", word_blanks, "\nAttempts remaining: ", attempts)
          try:
            if(int(win) == 1):
              print("!!!!!!!!!!!!You won the game!!!!!!!!!!!!!")
          except:
              print("You haven't won yet!")
        else:
          print("Received response ", na, " from server.\nNo ongoing game exists!")

        break
        
          
      if(action[0] == 'end'):
        
        na, addr = udpSocket.recvfrom(1024)
        na = na.decode('utf-8')
        print(na)
        if(na == 'Active'):
          word,addr= udpSocket.recvfrom(1024)
          word = word.decode('utf-8')
          print("Good luck! Word was ", word)
          break
        else:
          print("Received response ", na, " from server.\nNo ongoing game exists!")
          break

     
        
        
        
                    
         

      # Break once receiving info and reprompt user
    #end of UDP loop

    # If end message received, end client process
    if end:
      break
  #end of Game loop

  # Close sockets
  print("Closing TCP and UDP sockets...")
  udpSocket.close()
  clientSocket.close()
 ###########################################

if __name__ == "__main__":
  main()
