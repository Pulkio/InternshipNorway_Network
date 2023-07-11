//MyGameInstance.h


// #pragma once est une directive de préprocesseur qui indique au compilateur 
// d'inclure le fichier d'en-tête actuel une seule fois lors de la compilation.
#pragma once

// CoreMinimal.h est un fichier d'en-tête qui inclut une variété de fonctionnalités de base de l'Unreal Engine.
#include "CoreMinimal.h"
// GameInstance.h est un fichier d'en-tête pour la classe de base UGameInstance.
#include "Engine/GameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"




// Le fichier est généré par Unreal Engine lors de la compilation.
#include "MyGameInstance.generated.h"


// Prédéclaration de la classe UFlutterMessagesToComputerAdapter.
// C'est une bonne pratique dans le développement C++ pour éviter les inclusions inutiles.
class UFlutterMessagesToComputerAdapter;

// UCLASS est une macro Unreal qui permet à Unreal de gérer correctement 
// le cycle de vie de l'objet et de fournir des fonctionnalités supplémentaires.
UCLASS()
class GETMESSAGESV2_API UMyGameInstance : public UGameInstance
{
    // GENERATED_BODY est une macro Unreal qui inclut des implémentations 
    // par défaut pour certaines méthodes de classe de base et permet à Unreal 
    // de gérer correctement le cycle de vie de l'objet.
    GENERATED_BODY()

public:
    // Déclaration du constructeur par défaut. Cette classe gère le HUD des messages qui apparait à l'écran au lancement du jeu.
    UMyGameInstance();

    UFUNCTION(BlueprintImplementableEvent, Category = "HUD")
        void UpdateHUD();

    void SetLastMessage(const FText& Text);

    UFUNCTION(BlueprintCallable, Category = "HUD")
        FText GetLastMessage() const { return LastMessage; }


    UFUNCTION(BlueprintCallable, Category = "HUD")
        void ResetCounterComputerAdapter();

    UPROPERTY(BlueprintReadWrite, Category = "HUD")
        FText LastMessage;



    // Redéfinition de la méthode Init de la classe parente UGameInstance.
    virtual void Init() override;
    //void ShowText(const FString& DisplayText);

private:
    // Déclaration de la propriété FlutterAdapter.
    // UPROPERTY est une macro qui permet à Unreal de gérer correctement 
    // le cycle de vie de cet objet, et offre également d'autres fonctionnalités 
    // comme la sérialisation et l'accessibilité dans l'éditeur de propriétés.
    UPROPERTY()
        UFlutterMessagesToComputerAdapter* FlutterAdapter;

    
};
