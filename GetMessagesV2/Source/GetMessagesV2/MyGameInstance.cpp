//MyGameInstance.cpp

// Nous incluons les fichiers d'en-tête nécessaires pour notre fichier source MyGameInstance.cpp
#include "MyGameInstance.h"
#include "Networking/FlutterMessagesToComputerAdapter.h"
#include "Misc/AssertionMacros.h" // Inclusion pour UE_LOG
#include "GameFramework/PlayerController.h"
#include "Engine/LocalPlayer.h"
#include "Containers/UnrealString.h"


// Constructeur de la classe UMyGameInstance.
// Cette méthode est appelée chaque fois qu'une instance de cette classe est créée.
UMyGameInstance::UMyGameInstance()
{
    // Nous créons une nouvelle instance de l'objet UFlutterMessagesToComputerAdapter
    // et l'assignons à notre membre de classe FlutterAdapter.
    // La méthode NewObject<U>() est une méthode Unreal qui crée un nouvel objet
    // du type spécifié comme argument de modèle.
    FlutterAdapter = NewObject<UFlutterMessagesToComputerAdapter>();
    // Nous appelons le setter pour définir l'instance du jeu.
    
}

// La méthode Init est généralement utilisée pour initialiser les ressources de classe 
// qui doivent être préparées avant l'utilisation de la classe.
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





