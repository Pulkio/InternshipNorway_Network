//MyGameInstance.cpp

// Nous incluons les fichiers d'en-tête nécessaires pour notre fichier source MyGameInstance.cpp
#include "MyGameInstance.h"
#include "Networking/FlutterMessagesToComputerAdapter.h"
#include "Misc/AssertionMacros.h" // Inclusion pour UE_LOG

// Constructeur de la classe UMyGameInstance.
// Cette méthode est appelée chaque fois qu'une instance de cette classe est créée.
UMyGameInstance::UMyGameInstance()
{
    // Nous créons une nouvelle instance de l'objet UFlutterMessagesToComputerAdapter
    // et l'assignons à notre membre de classe FlutterAdapter.
    // La méthode NewObject<U>() est une méthode Unreal qui crée un nouvel objet
    // du type spécifié comme argument de modèle.
    FlutterAdapter = NewObject<UFlutterMessagesToComputerAdapter>();

    // Nous vérifions si FlutterAdapter est correctement initialisé.
    if (!FlutterAdapter)
    {
        // Si ce n'est pas le cas, nous enregistrons un message d'erreur.
        UE_LOG(LogTemp, Error, TEXT("La création de FlutterAdapter a échoué"));
    }
}

// La méthode Init est généralement utilisée pour initialiser les ressources de classe 
// qui doivent être préparées avant l'utilisation de la classe.
void UMyGameInstance::Init()
{
    // Nous appelons Super::Init() pour nous assurer que toute initialisation 
    // de la classe parente (UGameInstance dans ce cas) est effectuée correctement.
    Super::Init();

    // Nous vérifions si notre objet FlutterAdapter a été correctement initialisé.
    if (FlutterAdapter)
    {
        // Si notre vérification est réussie, nous utilisons notre objet FlutterAdapter 
        // pour envoyer un message au module Flutter pour commencer la connexion à l'ordinateur.
        FlutterAdapter->SendFlutterMessage("StartConnexionToComputer");

        // Ensuite, nous disons à notre FlutterAdapter de commencer à écouter les messages entrants.
        FlutterAdapter->ListenForMessages();
    }
    else
    {
        // Si FlutterAdapter est null, nous enregistrons un autre message d'erreur.
        UE_LOG(LogTemp, Error, TEXT("FlutterAdapter n'est pas initialisé dans la méthode Init"));
    }
}
