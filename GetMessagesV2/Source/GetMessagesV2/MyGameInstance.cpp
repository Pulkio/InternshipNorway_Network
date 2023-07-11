//MyGameInstance.cpp

// Nous incluons les fichiers d'en-t�te n�cessaires pour notre fichier source MyGameInstance.cpp
#include "MyGameInstance.h"
#include "Networking/FlutterMessagesToComputerAdapter.h"
#include "Misc/AssertionMacros.h" // Inclusion pour UE_LOG
#include "GameFramework/PlayerController.h"
#include "Engine/LocalPlayer.h"
#include "Containers/UnrealString.h"


// Constructeur de la classe UMyGameInstance.
// Cette m�thode est appel�e chaque fois qu'une instance de cette classe est cr��e.
UMyGameInstance::UMyGameInstance()
{
    // Nous cr�ons une nouvelle instance de l'objet UFlutterMessagesToComputerAdapter
    // et l'assignons � notre membre de classe FlutterAdapter.
    // La m�thode NewObject<U>() est une m�thode Unreal qui cr�e un nouvel objet
    // du type sp�cifi� comme argument de mod�le.
    FlutterAdapter = NewObject<UFlutterMessagesToComputerAdapter>();
    // Nous appelons le setter pour d�finir l'instance du jeu.
    
}

// La m�thode Init est g�n�ralement utilis�e pour initialiser les ressources de classe 
// qui doivent �tre pr�par�es avant l'utilisation de la classe.
void UMyGameInstance::Init()
{
    Super::Init();

    if (FlutterAdapter)
    {
        FlutterAdapter->SetGameInstance(this);
        SetLastMessage(FText::FromString("Ceci est un test"));
        FlutterAdapter->SendFlutterMessage("StartConnexionToComputer");
        FlutterAdapter->ListenForMessages();
    }
    else
    {
        // Log or handle the error
        UE_LOG(LogTemp, Warning, TEXT("FlutterAdapter is null"));
    }
}



void UMyGameInstance::SetLastMessage(const FText& Text)
{
    LastMessage = Text;
    UpdateHUD();  // Update the HUD each time we set a new messages
}

void UMyGameInstance::ResetCounterComputerAdapter() {
    FlutterAdapter->ResetCounterComputer();
}





