//MyGameInstance.h


// #pragma once est une directive de pr�processeur qui indique au compilateur 
// d'inclure le fichier d'en-t�te actuel une seule fois lors de la compilation.
#pragma once

// CoreMinimal.h est un fichier d'en-t�te qui inclut une vari�t� de fonctionnalit�s de base de l'Unreal Engine.
#include "CoreMinimal.h"
// GameInstance.h est un fichier d'en-t�te pour la classe de base UGameInstance.
#include "Engine/GameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"




// Le fichier est g�n�r� par Unreal Engine lors de la compilation.
#include "MyGameInstance.generated.h"


// Pr�d�claration de la classe UFlutterMessagesToComputerAdapter.
// C'est une bonne pratique dans le d�veloppement C++ pour �viter les inclusions inutiles.
class UFlutterMessagesToComputerAdapter;

// UCLASS est une macro Unreal qui permet � Unreal de g�rer correctement 
// le cycle de vie de l'objet et de fournir des fonctionnalit�s suppl�mentaires.
UCLASS()
class GETMESSAGESV2_API UMyGameInstance : public UGameInstance
{
    // GENERATED_BODY est une macro Unreal qui inclut des impl�mentations 
    // par d�faut pour certaines m�thodes de classe de base et permet � Unreal 
    // de g�rer correctement le cycle de vie de l'objet.
    GENERATED_BODY()

public:
    // D�claration du constructeur par d�faut. Cette classe g�re le HUD des messages qui apparait � l'�cran au lancement du jeu.
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



    // Red�finition de la m�thode Init de la classe parente UGameInstance.
    virtual void Init() override;
    //void ShowText(const FString& DisplayText);

private:
    // D�claration de la propri�t� FlutterAdapter.
    // UPROPERTY est une macro qui permet � Unreal de g�rer correctement 
    // le cycle de vie de cet objet, et offre �galement d'autres fonctionnalit�s 
    // comme la s�rialisation et l'accessibilit� dans l'�diteur de propri�t�s.
    UPROPERTY()
        UFlutterMessagesToComputerAdapter* FlutterAdapter;

    
};
