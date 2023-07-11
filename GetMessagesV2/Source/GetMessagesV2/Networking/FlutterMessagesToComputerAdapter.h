// FlutterMessagesToComputerAdapter.h


// #pragma once est une directive de préprocesseur qui indique au compilateur 
// d'inclure le fichier d'en-tête actuel une seule fois lors de la compilation.
#pragma once

// CoreMinimal.h est un fichier d'en-tête qui inclut une variété de fonctionnalités de base de l'Unreal Engine.
#include "CoreMinimal.h"
#include "../MyGameInstance.h"
// Le fichier est généré par Unreal Engine lors de la compilation.
#include "FlutterMessagesToComputerAdapter.generated.h"

// Prédéclaration de la classe FlutterMessagesToComputer.
// C'est une bonne pratique dans le développement C++ pour éviter les inclusions inutiles.
class FlutterMessagesToComputer;

// UCLASS est une macro Unreal qui permet à Unreal de gérer correctement 
// le cycle de vie de l'objet et de fournir des fonctionnalités supplémentaires.
UCLASS()
class GETMESSAGESV2_API UFlutterMessagesToComputerAdapter : public UObject
{
    // GENERATED_BODY est une macro Unreal qui inclut des implémentations 
    // par défaut pour certaines méthodes de classe de base et permet à Unreal 
    // de gérer correctement le cycle de vie de l'objet.
    GENERATED_BODY()

public:
    // Déclaration du constructeur et du destructeur.
    UFlutterMessagesToComputerAdapter(UMyGameInstance* gameInstance);
    UFlutterMessagesToComputerAdapter();
    virtual ~UFlutterMessagesToComputerAdapter();

    void SetGameInstance(UMyGameInstance* gameInstanceArg);
   

    // Les UFUNCTIONs sont des macros spéciales Unreal qui permettent à Unreal 
    // de reconnaître et de manipuler ces méthodes de manière particulière.
    // Ici, ces méthodes sont marquées comme étant appelables à partir de Blueprints.
    // Leur catégorie est également spécifiée comme "Flutter Messages".
    UFUNCTION(BlueprintCallable, Category = "Flutter Messages")
        int SendFlutterMessage(const FString& message);

    UFUNCTION(BlueprintCallable, Category = "Flutter Messages")
        void ListenForMessages();

    void ResetCounterComputer();

private:
    // Une instance de FlutterMessagesToComputer est déclarée comme membre privé de la classe.
    FlutterMessagesToComputer* flutterMessages;
    UMyGameInstance* gameInstance;  // Ajouter un attribut pour gameInstance
    
};
