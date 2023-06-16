//FlutterMessagesToComputer.h

// Nous commençons par une vérification pour voir si notre identifiant de garde d'en-tête, 
// FLUTTER_MESSAGES_TO_COMPUTER_H, a été défini. Si ce n'est pas le cas, nous le définissons. 
// Cela sert à empêcher les inclusions multiples du même fichier d'en-tête, 
// ce qui pourrait causer des problèmes de compilation.
#ifndef FLUTTER_MESSAGES_TO_COMPUTER_H
#define FLUTTER_MESSAGES_TO_COMPUTER_H

// winsock2.h est un fichier d'en-tête pour le Winsock 2 library qui fournit 
// les fonctionnalités réseau sur les systèmes Windows.
#include <winsock2.h>
// Ws2tcpip.h est un fichier d'en-tête qui fournit des définitions pour des fonctions 
// et des structures utilisées avec le protocole TCP/IP.
#include <Ws2tcpip.h>
// Nous incluons également <string> pour pouvoir utiliser le type de données string.
#include <string>

// Définition de la classe FlutterMessagesToComputer.
class FlutterMessagesToComputer {
public:
    // Le constructeur par défaut et le destructeur pour la classe.
    FlutterMessagesToComputer();
    ~FlutterMessagesToComputer();

    // Une méthode pour envoyer des messages à travers la connexion.
    // Elle prend une référence constante vers une chaîne comme argument (le message à envoyer),
    // et renvoie un entier comme code d'état.
    int SendMessage(const std::string& message);

    // Une méthode pour écouter les messages entrants sur la connexion.
    // Elle renvoie un entier comme code d'état.
    int ListenForMessages();

private:
    // Un objet SOCKET qui représente la connexion au serveur.
    SOCKET sock;

    // Une structure sockaddr_in qui contient les détails de l'adresse du serveur.
    sockaddr_in serverAddress;

    // Des méthodes privées pour initialiser Winsock, créer le socket, 
    // et configurer l'adresse du serveur. Chacune renvoie un entier comme code d'état.
    int InitializeWinsock();
    int CreateSocket();
    int SetupServerAddress();
};

// Nous terminons notre vérification de l'identifiant de garde d'en-tête. 
// Si FLUTTER_MESSAGES_TO_COMPUTER_H était déjà défini au début du fichier, 
// tout le code entre le #ifndef et le #endif sera ignoré par le préprocesseur.
#endif // FLUTTER_MESSAGES_TO_COMPUTER_H
