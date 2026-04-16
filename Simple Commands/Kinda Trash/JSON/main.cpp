#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json.hpp" // Kütüphaneyi dahil ediyoruz

using json = nlohmann::json;

struct Note {
    int id;
    std::string content;
};

// Not listesini JSON dosyasına kaydetme
void saveToJson(const std::vector<Note>& notes) {
    json j_list = json::array(); // JSON dizisi oluşturuyoruz

    for (const auto& note : notes) {
        json j_note;
        j_note["id"] = note.id;
        j_note["content"] = note.content;
        j_list.push_back(j_note);
    }

    std::ofstream file("notes.json");
    if (file.is_open()) {
        file << j_list.dump(4); // 4 boşluk bırakarak (indent) güzel formatta kaydeder
        file.close();
        std::cout << "Veriler basariyla kaydedildi." << std::endl;
    }
}

// JSON dosyasından verileri yükleme
void loadFromJson(std::vector<Note>& notes) {
    std::ifstream file("notes.json");
    if (!file.is_open()) {
        std::cout << "Dosya bulunamadi, yeni liste olusturuluyor." << std::endl;
        return;
    }

    json j_list;
    file >> j_list; // Dosya içeriğini JSON nesnesine aktar

    notes.clear();
    for (const auto& item : j_list) {
        Note n;
        n.id = item["id"];
        n.content = item["content"];
        notes.push_back(n);
    }
    file.close();
    std::cout << "Veriler dosyadan yuklendi." << std::endl;
}

int main() {
    std::vector<Note> myNotes;

    // 1. Uygulama açılışında yükle
    loadFromJson(myNotes);

    // 2. Örnek bir not ekleyelim (Eğer liste boşsa)
    if (myNotes.empty()) {
        myNotes.push_back({1, "Ilk notum"});
        myNotes.push_back({2, "JSON ogreniyorum"});
    }

    // 3. Notları ekrana basalım
    for (const auto& n : myNotes) {
        std::cout << "ID: " << n.id << " | Not: " << n.content << std::endl;
    }

    // 4. Uygulama kapanırken kaydet
    saveToJson(myNotes);

    return 0;
}