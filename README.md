# Realtime Messaging System for Unreal Engine Game Using Flutter and Google Cloud Server

This repository contains the code for an application I have developed to send real-time messages from a mobile device to Unreal Engine as part of a video game project. To accommodate the real-time requirements and the need for speed, I used the User Datagram Protocol (UDP) which is significantly faster than the Transmission Control Protocol (TCP). The code was potentially also to be used to control a drone using the smartphone in real time, which was not done, but which should work with this code. This code works in real time, and could have been much simplified if used only for sending messages.

# Components

The system consists of three main components:

    A Flutter application, which sends UDP messages to a server on a cloud.
    A cloud Server, which receives and then forwards these messages to Unreal Engine.
    An Unreal Engine game that receives the messages and put them on the screen.

The code for the Flutter application can be found in the applicationFlutter directory, while the server-side code can be found in the server directory.
# Google Cloud Server

The server is hosted on Google Cloud, taking advantage of the free trial period of 2 months. It's a Node.js server that listens for messages from the Flutter app and forwards them to Unreal Engine.

# UDP Messaging and Firewall Bypass

Due to the project's target deployment in a school network, one challenge was to bypass the university firewall. By default, incoming UDP packets would be blocked by the firewall. However, by establishing the connection from Unreal Engine to the Google Cloud server first, the server is then able to respond and the UDP packets can pass without issues.

# Unreal Engine and Winsock

Unreal Engine has capabilities for sending UDP packets but has limited support for reading them, hence, I used Winsock and wrote a C++ function to send and listen for UDP messages. This function then sends the messages to Unreal Engine's logs. The corresponding code can be found in the GetMessagesV2 directory.
# Instructions

To use this application, you should:

    Start the Google Cloud Server.
    Launch the Unreal Engine game.
    Launch the Flutter application and send messages.

If the messages are not appearing in Unreal Engine, you can check whether they are being sent to the server by viewing the Google Cloud console.

# Explications

This project is not functional as is, it only includes the necessary files to rebuild it. You'll need to change the ports and IP addresses according to your server settings. In the Unreal Engine part, you have only the code and HUD available.

Here's how the code works:

There are the files MyGameInstance.cpp and .h, which constitute the game instance. So, remember to set your default instance as MyGameInstance. MyGameInstance initializes FlutterMessagesToComputerAdapteur. The FlutterMessagesToComputerAdapteur class bridges MyGameInstance, which is the game instance, and FlutterMessagesToComputer which is pure C++ code, handling the sending and receiving of messages.

In the level blueprint, remember to create an EventGraph. In this event graph, you should place three events:

![level_BP](https://github.com/Pulkio/InternshipNorway_Network/assets/57195076/9537a8f6-06b6-4112-b873-8afe46a26d1e)

    An EventBeginPlay connected to CreateMyWidgetHUD widget, connected to SET, then connected to Add to Viewport.

    Another event: Event Tick connected to Cast To MyGameInstance then GetLastMessage and SetTextMessages which targets the HUD.

    Finally, an Event R (which I put in but you can change) which, when pressed, calls Cast To MyGameInstance, then Reset Counter Computer Adapter.
    
You also need to create the HUD and be carefull about the naming to keep the logic between the code and the HUD. 

![HUD_Widget](https://github.com/Pulkio/InternshipNorway_Network/assets/57195076/3c04967b-7fc8-4893-b736-b162b63e5c68)

In the blueprint of my HUD, insert the SetTextMessages function, connected to SetText with a target variable TB Messages, which is a TextWidget.

![HUD_BP](https://github.com/Pulkio/InternshipNorway_Network/assets/57195076/de7b6b60-d9ac-47b2-ba4b-27fc86ab90a5)
