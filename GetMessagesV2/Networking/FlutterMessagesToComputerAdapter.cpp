// FlutterMessagesToComputerAdapter.cpp

// Nous incluons les fichiers d'en-tête nécessaires pour ce fichier source.
#include "FlutterMessagesToComputerAdapter.h"
#include "FlutterMessagesToComputer.h"

// Constructeur de la classe UFlutterMessagesToComputerAdapter.
UFlutterMessagesToComputerAdapter::UFlutterMessagesToComputerAdapter()
{
    // Nous créons une nouvelle instance de l'objet FlutterMessagesToComputer
    // et l'assignons à notre membre de classe flutterMessages.
    flutterMessages = new FlutterMessagesToComputer();
}

// Destructeur de la classe UFlutterMessagesToComputerAdapter.
UFlutterMessagesToComputerAdapter::~UFlutterMessagesToComputerAdapter()
{
    // Nous supprimons notre objet flutterMessages pour libérer la mémoire qu'il occupait.
    delete flutterMessages;
}

// Implémentation de la méthode SendFlutterMessage.
int UFlutterMessagesToComputerAdapter::SendFlutterMessage(const FString& message)
{
    // Nous enregistrons un message de journalisation indiquant que nous sommes sur le point d'envoyer un paquet UDP.
    UE_LOG(LogTemp, Warning, TEXT("Envoi du premier paquet UDP..."));

    // Nous convertissons notre FString en std::string pour qu'elle puisse être utilisée par notre objet flutterMessages.
    std::string messageStr(TCHAR_TO_UTF8(*message));

    // Nous appelons la méthode SendMessage de notre objet flutterMessages et retournons son code de retour.
    return flutterMessages->SendMessage(messageStr);
}

// Implémentation de la méthode ListenForMessages.
void UFlutterMessagesToComputerAdapter::ListenForMessages()
{
    // Nous enregistrons un message de journalisation indiquant que nous sommes sur le point de commencer à écouter les paquets UDP.
    UE_LOG(LogTemp, Warning, TEXT("Listen for paquet UDP..."));

    // Nous lançons une tâche asynchrone pour écouter les messages.
    // Cela permet à notre jeu de continuer à fonctionner pendant que nous attendons les messages.
    AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this]() {
        // Nous enregistrons un message de journalisation indiquant que nous avons lancé notre tâche asynchrone.
        UE_LOG(LogTemp, Error, TEXT("Asynchronus TASK..."));

        // Nous appelons la méthode ListenForMessages de notre objet flutterMessages pour commencer à écouter les messages.
        flutterMessages->ListenForMessages();
        });
}
