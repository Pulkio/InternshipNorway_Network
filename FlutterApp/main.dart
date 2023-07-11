import 'dart:async';
import 'dart:io';
import 'package:flutter/material.dart';
import 'package:udp/udp.dart'; // Package for sending UDP messages

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: MyHomePage(),
    );
  }
}

class MyHomePage extends StatefulWidget {
  MyHomePage({Key? key}) : super(key: key);

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  final String serverIp = 'server IP';
  final int serverPort = 50001; //The port you choose

  Future<bool> sendMessage(String message) async {
    UDP? sender;
    try {
      sender = await UDP.bind(Endpoint.any());
      var dataLength = await sender.send(
        message.codeUnits,
        Endpoint.unicast(InternetAddress(serverIp), port: Port(serverPort)),
      );

      print('Message sent: $message with a length of $dataLength');

      return true;
    } catch (e) {
      print('Cannot send to $serverIp:$serverPort: $e');
      return false;
    } finally {
      sender?.close();
    }
  }

  @override
  Widget build(BuildContext context) {
    double buttonHeight = MediaQuery.of(context).size.height * 0.25;  // calculate 1/4th of screen height
    return Scaffold(
      appBar: AppBar(
        title: Text('UDP Message Sender'),
      ),
      body: Center(
        child: Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Container(
              height: buttonHeight,
              margin: EdgeInsets.all(20.0),
              child: ElevatedButton(
                onPressed: () async {
                  bool messageSent = await sendMessage("Reponse 1");

                  if (messageSent) {
                    ScaffoldMessenger.of(context).showSnackBar(
                      SnackBar(
                        content: Text('Le message a été envoyé avec succès.'),
                        backgroundColor: Colors.green,
                      ),
                    );
                  } else {
                    ScaffoldMessenger.of(context).showSnackBar(
                      SnackBar(
                        content: Text('Une erreur s\'est produite lors de l\'envoi du message.'),
                        backgroundColor: Colors.red,
                      ),
                    );
                  }
                },
                child: Text('Reponse1'),
                style: ElevatedButton.styleFrom(primary: Colors.green),
              ),
            ),
            Container(
              height: buttonHeight,
              margin: EdgeInsets.all(20.0),
              child: ElevatedButton(
                onPressed: () async {
                  bool messageSent = await sendMessage("Reponse 2");

                  if (messageSent) {
                    ScaffoldMessenger.of(context).showSnackBar(
                      SnackBar(
                        content: Text('Le message a été envoyé avec succès.'),
                        backgroundColor: Colors.green,
                      ),
                    );
                  } else {
                    ScaffoldMessenger.of(context).showSnackBar(
                      SnackBar(
                        content: Text('Une erreur s\'est produite lors de l\'envoi du message.'),
                        backgroundColor: Colors.red,
                      ),
                    );
                  }
                },
                child: Text('Reponse2'),
                style: ElevatedButton.styleFrom(primary: Colors.blue),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
