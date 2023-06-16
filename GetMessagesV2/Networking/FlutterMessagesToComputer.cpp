//FlutterMessagesToComputer.cpp


// Les fichiers d'en-tête nécessaires pour ce fichier sont inclus.
#include "FlutterMessagesToComputer.h"
#include <iostream>

// Ce fichier est lié avec la bibliothèque Ws2_32.lib, qui est nécessaire pour la programmation de sockets sur Windows.
#pragma comment(lib, "Ws2_32.lib")

// Constructeur de la classe FlutterMessagesToComputer.
FlutterMessagesToComputer::FlutterMessagesToComputer() {
    // Appelle les fonctions pour initialiser Winsock, créer le socket et configurer l'adresse du serveur.
    InitializeWinsock();
    CreateSocket();
    SetupServerAddress();
}

// Destructeur de la classe FlutterMessagesToComputer.
FlutterMessagesToComputer::~FlutterMessagesToComputer() {
    // Ferme le socket et effectue un nettoyage final de Winsock.
    closesocket(sock);
    WSACleanup();
}

int FlutterMessagesToComputer::InitializeWinsock() {
    // Initialise Winsock.
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        // Si WSAStartup échoue, affiche un message d'erreur.
        std::cerr << "WSAStartup failed: " << iResult << "\n";
        return 1;
    }
    return 0;
}

int FlutterMessagesToComputer::CreateSocket() {
    // Crée un socket UDP.
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == INVALID_SOCKET) {
        // Si la création du socket échoue, affiche un message d'erreur et nettoie Winsock.
        std::cerr << "socket failed with error: " << WSAGetLastError() << "\n";
        WSACleanup();
        return 1;
    }
    return 0;
}

int FlutterMessagesToComputer::SetupServerAddress() {
    // Configure l'adresse du serveur.
    serverAddress = {};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(50001); // Port du serveur
    inet_pton(AF_INET, "35.228.26.217", &(serverAddress.sin_addr)); // Adresse IP du serveur
    return 0;
}

int FlutterMessagesToComputer::SendMessage(const std::string& message) {
    // Envoie un message à l'adresse du serveur.
    if (sendto(sock, message.c_str(), message.size(), 0, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        // Si l'envoi échoue, affiche un message d'erreur, ferme le socket et nettoie Winsock.
        std::cerr << "sendto failed with error: " << WSAGetLastError() << "\n";
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    std::cout << "Message initial envoyé\n";
    return 0;
}

int FlutterMessagesToComputer::ListenForMessages() {
    // Écoute les messages entrants.
    char recvbuf[1024];
    int recvbuflen = 1024;
    sockaddr_in senderAddr{};
    int senderAddrSize = sizeof(senderAddr);
    int iResult = 0;  // Initialisation de iResult

    while (true) { // Modifié do-while en boucle while(true)
        // Réinitialise le tampon avant de recevoir de nouvelles données.
        memset(recvbuf, 0, sizeof(recvbuf));

        iResult = recvfrom(sock, recvbuf, recvbuflen, 0, (struct sockaddr*)&senderAddr, &senderAddrSize);
        if (iResult > 0) {
            // Si des données ont été reçues, affiche le message.
            FString Message = FString(recvbuf, iResult); // Nouveau message reçu
            FString Infos = FString::Printf(TEXT("Infos: %s"), UTF8_TO_TCHAR(inet_ntoa(senderAddr.sin_addr)));

            UE_LOG(LogTemp, Warning, TEXT("Asynchronous TASK..."));
            UE_LOG(LogTemp, Warning, TEXT("Message reçu: %s"), *Message);
            UE_LOG(LogTemp, Warning, TEXT("%s"), *Infos);

            std::cout << "Message reçu: " << std::string(recvbuf, iResult) << "\n";
            std::cout << "Infos: " << inet_ntoa(senderAddr.sin_addr) << "\n";
        }
        else if (iResult == 0)
            std::cout << "Connection closed\n";
        else
            std::cerr << "recvfrom failed with error: " << WSAGetLastError() << "\n";
    }

    return 0;
}
