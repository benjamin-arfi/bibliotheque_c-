#include <iostream>
#include <vector>

struct Livre {
    std::string titre;
    std::string auteur;
    int annee;
};

std::vector<Livre> bibliotheque; // Utilisation d'un vecteur pour stocker les livres

void ajouterLivre() {
    Livre livre;
    
    std::cout << "Titre : ";
    std::getline(std::cin >> livre.titre); // Utilisation de getline pour lire le titre avec les espaces
    
    std::cout << "Auteur : ";
    std::getline(std::cin >> livre.auteur);
    
    std::cout << "Année : ";
    std::cin >> livre.annee;
    
    bibliotheque.push_back(livre);
    
    std::cout << "Livre ajouté avec succès !" << std::endl;
}

void supprimerLivre() {
    std::string titre;
    std::cout << "Entrez le titre du livre à supprimer : ";
    std::getline(std::cin >> titre);
    
    // Parcourir la bibliothèque et supprimer le livre correspondant
    for (auto it = bibliotheque.begin(); it != bibliotheque.end(); ++it) {
        if (it->titre == titre) {
            bibliotheque.erase(it);
            std::cout << "Livre supprimé avec succès !" << std::endl;
            return;
        } else
        {
            std::cout << "Livre introuvable." << std::endl;
        }
        
    }
    
    
}

void modifierLivre() {
    std::string titre;
    std::cout << "Entrez le titre du livre à modifier : ";
    std::getline(std::cin >> std::ws, titre);
    
    // Parcourir la bibliothèque et rechercher le livre correspondant
    for (auto& livre : bibliotheque) {
        if (livre.titre == titre) {
            std::cout << "Nouveau titre : ";
            std::getline(std::cin >> std::ws, livre.titre);
            
            std::cout << "Nouvel auteur : ";
            std::getline(std::cin >> std::ws, livre.auteur);
            
            std::cout << "Nouvelle année : ";
            std::cin >> livre.annee;
            
            std::cout << "Livre modifié avec succès !" << std::endl;
            return;
        }
    }
    
    std::cout << "Livre introuvable." << std::endl;
}

void afficherBibliotheque() {
    std::cout << "----- Bibliothèque -----" << std::endl;
    
    for (const auto& livre : bibliotheque) {
        std::cout << "Titre : " << livre.titre << std::endl;
        std::cout << "Auteur : " << livre.auteur << std::endl;
        std::cout << "Année : " << livre.annee << std::endl;
        std::cout << "------------------------" << std::endl;
    }
    
    std::cout << "Nombre total de livres : " << bibliotheque.size() << std::endl;
}

int main() {
    int choix;
    
    do {
        std::cout << "----- Menu -----" << std::endl;
        std::cout << "1. Ajouter un livre" << std::endl;
        std::cout << "2. Supprimer un livre" << std::endl;
        std::cout << "3. Modifier un livre" << std::endl;
        std::cout << "4. Afficher la bibliothèque" << std::endl;
        std::cout << "0. Quitter" << std::endl;
        std::cout << "----------------" << std::endl;
        std::cout << "Votre choix : ";
        std::cin >> choix;
        
        switch (choix) {
            case 1:
                ajouterLivre();
                break;
            case 2:
                supprimerLivre();
                break;
            case 3:
                modifierLivre();
                break;
            case 4:
                afficherBibliotheque();
                break;
            case 0:
                std::cout << "Au revoir !" << std::endl;
                break;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
                break;
        }
        
        std::cout << std::endl;
    } while (choix != 0);
    
    return 0;
}

