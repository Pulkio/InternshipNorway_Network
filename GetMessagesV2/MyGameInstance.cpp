//MyGameInstance.cpp

// Nous incluons les fichiers d'en-t�te n�cessaires pour notre fichier source MyGameInstance.cpp
#include "MyGameInstance.h"
#include "Networking/FlutterMessagesToComputerAdapter.h"
#include "Misc/AssertionMacros.h" // Inclusion pour UE_LOG

// Constructeur de la classe UMyGameInstance.
// Cette m�thode est appel�e chaque fois qu'une instance de cette classe est cr��e.
UMyGameInstance::UMyGameInstance()
{
    // Nous cr�ons une nouvelle instance de l'objet UFlutterMessagesToComputerAdapter
    // et l'assignons � notre membre de classe FlutterAdapter.
    // La m�thode NewObject<U>() est une m�thode Unreal qui cr�e un nouvel objet
    // du type sp�cifi� comme argument de mod�le.
    FlutterAdapter = NewObject<UFlutterMessagesToComputerAdapter>();

    // Nous v�rifions si FlutterAdapter est correctement initialis�.
    if (!FlutterAdapter)
    {
        // Si ce n'est pas le cas, nous enregistrons un message d'erreur.
        UE_LOG(LogTemp, Error, TEXT("La cr�ation de FlutterAdapter a �chou�"));
    }
}

// La m�thode Init est g�n�ralement utilis�e pour initialiser les ressources de classe 
// qui doivent �tre pr�par�es avant l'utilisation de la classe.
void UMyGameInstance::Init()
{
    // Nous appelons Super::Init() pour nous assurer que toute initialisation 
    // de la classe parente (UGameInstance dans ce cas) est effectu�e correctement.
    Super::Init();

    // Nous v�rifions si notre objet FlutterAdapter a �t� correctement initialis�.
    if (FlutterAdapter)
    {
        // Si notre v�rification est r�ussie, nous utilisons notre objet FlutterAdapter 
        // pour envoyer un message au module Flutter pour commencer la connexion � l'ordinateur.
        FlutterAdapter->SendFlutterMessage("StartConnexionToComputer");

        // Ensuite, nous disons � notre FlutterAdapter de commencer � �couter les messages entrants.
        FlutterAdapter->ListenForMessages();
    }
    else
    {
        // Si FlutterAdapter est null, nous enregistrons un autre message d'erreur.
        UE_LOG(LogTemp, Error, TEXT("FlutterAdapter n'est pas initialis� dans la m�thode Init"));
    }
}
