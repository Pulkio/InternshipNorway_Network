// Import the necessary packages
import 'dart:async';
import 'dart:io';
import 'package:flutter/material.dart';
import 'package:udp/udp.dart'; // Package for sending UDP messages

void main() {
  runApp(MyApp());
}

// This widget is the root of your application.
class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // Returns a MaterialApp widget
    return MaterialApp(
      home: MyHomePage(), // Sets the home as MyHomePage widget
    );
  }
}

// This widget is the home page of your application.
class MyHomePage extends StatefulWidget {
  MyHomePage({Key? key}) : super(key: key);

  @override
  _MyHomePageState createState() => _MyHomePageState(); // Creates the mutable state for this widget
}

class _MyHomePageState extends State<MyHomePage> {
  // The IP address and port of the server.
  final String serverIp = '35.228.26.217';
  final int serverPort = 50001;

  // This controller is responsible for reading the input field's text.
  final TextEditingController messageController = TextEditingController();

  // This function sends a message via UDP to the server.
  // It returns true if the message is sent successfully, and false if an error occurs.
  Future<bool> sendMessage(String message) async {
    UDP? sender; // sender is nullable now
    try {
      // Creates a UDP instance and binds it to an endpoint
      sender = await UDP.bind(Endpoint.any());

      // Sends the message to the specified server
      var dataLength = await sender.send(
        message.codeUnits, // The message is converted to a list of ASCII values
        Endpoint.unicast(InternetAddress(serverIp), port: Port(serverPort)), // The endpoint of the receiver
      );

      print('Message senta: $message with a length of $dataLength');

      return true; // Returns true if the message is sent successfully.
    } catch (e) {
      print('Cannot send to $serverIp:$serverPort: $e');
      return false; // Returns false if an error occurs while sending the message.
    } finally {
      // Close the UDP sender after the message has been sent
      sender?.close();
    }
  }


  // This function is responsible for building the UI of the application
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('UDP Message Sender'), // The title of the application
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            TextField(
              controller: messageController,
              decoration: InputDecoration(
                border: OutlineInputBorder(),
                labelText: 'Message',
              ),
            ),
            SizedBox(height: 10), // Adds a 10-pixel spacing between the TextField and the ElevatedButton
            ElevatedButton(
              onPressed: () async { // Made the onPressed function asynchronous so it can wait for the result of sendMessage.
                String message = messageController.text;
                if (message.isNotEmpty) {
                  bool messageSent = await sendMessage(message); // Waits for sendMessage to complete and gets the result.

                  if (messageSent) {
                    // Displays a confirmation SnackBar if the message is sent successfully.
                    ScaffoldMessenger.of(context).showSnackBar(
                      SnackBar(
                        content: Text('Le message a été envoyé avec succès.'),
                        backgroundColor: Colors.green,
                      ),
                    );
                  } else {
                    // Displays an error SnackBar if the message cannot be sent.
                    ScaffoldMessenger.of(context).showSnackBar(
                      SnackBar(
                        content: Text('Une erreur s\'est produite lors de l\'envoi du message.'),
                        backgroundColor: Colors.red,
                      ),
                    );
                  }
                } else {
                  // Displays a SnackBar asking for input if the TextField is empty
                  ScaffoldMessenger.of(context).showSnackBar(
                    SnackBar(
                      content: Text('Veuillez entrer un message.'),
                      backgroundColor: Colors.orange,
                    ),
                  );
                }
              },
              child: Text('Send'), // The text on the button
            ),
          ],
        ),
      ),
    );
  }
}
