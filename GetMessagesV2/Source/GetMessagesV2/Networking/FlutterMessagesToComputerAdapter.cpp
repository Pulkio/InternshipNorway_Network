// FlutterMessagesToComputerAdapter.cpp

// Nous incluons les fichiers d'en-tête nécessaires pour ce fichier source.
#include "FlutterMessagesToComputerAdapter.h"
#include "FlutterMessagesToComputer.h"

//Constructeur de FlutterMessagesToComputerAdapteur qui construit un nouveau FlutterMessagesToComputer
UFlutterMessagesToComputerAdapter::UFlutterMessagesToComputerAdapter()
{
    flutterMessages = new FlutterMessagesToComputer();
}


//Set la game instance qu'il n'est pas possible de mettre directement dans le constructeur
void UFlutterMessagesToComputerAdapter::SetGameInstance(UMyGameInstance* gameInstanceArg)
{
    gameInstance = gameInstanceArg;
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


//Appelle resetCounters de FlutterMessagesToComputer
void UFlutterMessagesToComputerAdapter::ResetCounterComputer() {
    flutterMessages->ResetCounters();
}

// Implémentation de la méthode ListenForMessages.
void UFlutterMessagesToComputerAdapter::ListenForMessages()
{
    // Nous enregistrons un message de journalisation indiquant que nous sommes sur le point de commencer à écouter les paquets UDP.
    UE_LOG(LogTemp, Warning, TEXT("Listen for paquet UDP..."));







    if (GEngine != nullptr) {
        if (gameInstance != nullptr) {
            AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this]() {
                UE_LOG(LogTemp, Error, TEXT("Asynchronous TASK..."));
                if (this->gameInstance != nullptr) {
                    UE_LOG(LogTemp, Error, TEXT("GameInstance NOT NULL..."));
                    flutterMessages->ListenForMessages(this->gameInstance);
                }
                else {
                    UE_LOG(LogTemp, Error, TEXT("GameInstance NULL..."));
                }
               
            });
        }
        else {
            UE_LOG(LogTemp, Warning, TEXT("GameInstance est null 1"));
        }
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("GEngine NULL"));
    }


}
