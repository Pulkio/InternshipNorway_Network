# Realtime Messaging System for Unreal Engine Game Using Flutter and Google Cloud Server

This repository contains the code for an application I have developed to send real-time messages from a mobile device to Unreal Engine as part of a video game project. The project also involves controlling a drone using a smartphone. To accommodate the real-time requirements and the need for speed, I used the User Datagram Protocol (UDP) which is significantly faster than the Transmission Control Protocol (TCP).
# Components

The system consists of three main components:

    A Flutter application, which sends UDP messages to a server on Google Cloud.
    A Google Cloud Server, which receives and then forwards these messages to Unreal Engine.
    An Unreal Engine game that receives the messages and logs them.

The code for the Flutter application can be found in the applicationFlutter directory, while the server-side code can be found in the server directory.
# Google Cloud Server

The server is hosted on Google Cloud, taking advantage of the free trial period of 2 months. It's a Node.js server that listens for messages from the Flutter app and forwards them to Unreal Engine.
#UDP Messaging and Firewall Bypass

Due to the project's target deployment in a school network, one challenge was to bypass the Unreal Engine's firewall. By default, incoming UDP packets would be blocked by the firewall. However, by establishing the connection from Unreal Engine to the Google Cloud server first, the server is then able to respond and the UDP packets can pass without issues.
#Unreal Engine and Winsock

Unreal Engine has capabilities for sending UDP packets but has limited support for reading them, hence, I used Winsock and wrote a C++ function to send and listen for UDP messages. This function then sends the messages to Unreal Engine's logs. The corresponding code can be found in the GetMessagesV2 directory.
# Instructions

To use this application, you should:

    Start the Google Cloud Server.
    Launch the Unreal Engine game.
    Launch the Flutter application and send messages.

If the messages are not appearing in Unreal Engine, you can check whether they are being sent to the server by viewing the Google Cloud console.

Note: There might be issues with displaying messages in the logs since message reception and logging occur in a separate thread in Unreal Engine to prevent blocking. This can sometimes cause problems with displaying messages from a different thread than the main game thread.
# Known Issues

    There may be issues with message display due to multi-threading in Unreal Engine.
