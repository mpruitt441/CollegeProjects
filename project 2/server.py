from socket import *
from sys import argv
from random import *
from game import *

def main():
  # Parse command line args
  if len(argv) != 2:
    print("usage: python3 server.py <word to guess or '-r' for random word>")
    return 1

  print("Server is running...")

  # Create the TCP Socket
  print("Creating TCP socket...")

  # Bind a port to the TCP socket, letting the OS choose the port number  
  serverSocket = socket(AF_INET,SOCK_STREAM)
  serverSocket.bind(("",0))
  sock = serverSocket.getsockname()[1]
  # Get the port number of the socket from the OS and print it
  print ("The TCP socket that has been chosen is", sock)
  # The port number will be a command-line parameter to the client program


  # Configure the TCP socket (using listen) to accept a connection request
  serverSocket.listen(1)
  try: # try/except to catch ctrl-c
    while True:
      na = "Inactive"
      print("Waiting for a client...")
      connectionSocket, addr = serverSocket.accept()
      
      # Accept the TCP Connection
      # TCP loop
      while True:
        # Continuously Read in from TCP port
       
        # Keep listening if it doesn't receive a hello message
        
        # Extract username handling empty case
        username = connectionSocket.recv(1024)
        print("hello username received")
        username = username.decode('utf-8')
        print(username)
        try:
          (username.split()[1] == "")
        except:
          print("Setting a random username...")
          username = "Bob"
          print("Username assigned is: ", username)


        # Create and bind a UDP socket, letting the OS choose the port number
        print("Creating UDP socket...")
        udpSocket = socket(AF_INET, SOCK_DGRAM)
        udpSocket.bind(("",0))
        sock = str(udpSocket.getsockname()[1])
        # Add a timeout to the UDP socket so that it stops listening after 2 minutes of inactivity
        udpSocket.settimeout(120)
        
        # Get the port number assigned by the OS and print to console
        print("UDP Socket is... ", sock) 

        # Put the UDP port number in a message and send it to the client using TCP
        print("Sending UDP port number to client using TCP connection...")
        connectionSocket.send(sock.encode('utf-8'))
        break
        # Break from loop once needed info is received

      active = False # game not active by default
      print("UDP port has been sent and established with client.")
      # Game (UDP) loop
      while True:
        try:
          #receive form UDP here
          print("Waiting on command from client: ")
          message, addr= udpSocket.recvfrom(1024)
          action = message
          action = action.decode('utf-8')
          action = action.split()
         
          
          if (action[0] == 'start'):
            print("Command is: ", action[0])
            active = True
            word, word_blanks, attempts, win = gameSetup(argv)
            print("Hidden Word: {}".format(word))
            print("Starting game...")
            udpSocket.sendto(INSTRUCTIONS.encode('utf-8'),addr)
            udpSocket.sendto(str(attempts).encode('utf-8'),addr)
            udpSocket.sendto(word.encode('utf-8'),addr)
            na = "Active"
          
          elif (action[0] == 'end'):
            udpSocket.sendto(na.encode('utf-8'),addr)
            if(active):
    
              active = False
              print("Ending current game...")
              udpSocket.sendto(word.encode('utf-8'),addr)
              
              na = "Inactive"
              
            else:
              print("No game currently active, sending na error to client:")
              

          elif (action[0] == 'guess'):
            udpSocket.sendto(na.encode('utf-8'),addr)
            
            if(active):
  
              guess = action[1]
              print ("Guess: ", guess)
              word_blanks, attempts, win = checkGuess(word, word_blanks, attempts, guess, win)
              
              udpSocket.sendto(word_blanks.encode('utf-8'), addr)
              udpSocket.sendto(str(attempts).encode('utf-8'),addr)
              udpSocket.sendto(str(win).encode('utf-8'),addr)
              
              if len(guess) > 1 and not win or attempts == 0 or win:
                active = False
                na ="Inactive"
            else:
              print("No ongoing game exists!")
          elif(action[0] == 'exit'):
            print("Closing sockets...")
            udpSocket.close()
            connectionSocket.close()
                   
          
            

        
          
          
          
        except timeout:
          print("Ending game due to timeout...")
          break #break and wait for another client



        # if ...:
        #   #Game setup
        #   active = True
        #   word, word_blanks, attempts, win = gameSetup(argv)
        #   print("Hidden Word: {}".format(word))
        #   print("Starting game...")

        #   #Send inst then stat messages


        # elif ...:

        #   word_blanks, attempts, win = checkGuess(word, word_blanks, attempts, guess, win)

        #   #Losing conditions - break if end
        #   if len(guess) > 1 and not win or attempts == 0 or win:
        #     #Handle win/lose conditions
        #     active = False
        #   else:


        # always send a response message to the client


      # end of UDP Game loop
      # close the TCP socket the client was using as well as the udp socket.


    # end of TCP loop

  except KeyboardInterrupt:

    # Close sockets
    print("Closing TCP and UDP sockets...")


###########################################

if __name__ == "__main__":
  main()
