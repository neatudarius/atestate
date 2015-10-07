var Database = angular.module('Database', []);
Database.factory('Database', function() {

    Database.get_products = function() {
        var products =
            [
                {
                    "name": "Zacuscă de vinete",
                    "description": "Zacuscă tradițională de vinete. Zacusca este facută din vinete și gogoșari copţi la grătar, ceapă, morcov, ulei, sare, foi de dafin și piper boabe.",
                    "image": "zacuscadevinete.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Bulion",
                    "description": "Bulionul este făcut din roșiile proaspete ale verii pentru mancărurile de mai târziu, în toamnă sau iarnă. Preparatul poate fi folosit în diverse feluri de mâncare: paste cu sos de bulion, ostropel de pui cu sos de bulion, spaghete cu bulion, spanac în bulion, ciorbă de varză cu bulion, supă de zarzavat cu bulion, frigărui cu bulion etc.",
                    "image": "bulion.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Bulion de roșii cu ardei kapia",
                    "description": "Preparatul poate fi folosit în diverse feluri de mâncare: paste cu sos de bulion, ostropel de pui cu sos de bulion, spaghete cu bulion, spanac în bulion, ciorbă de varză cu bulion, supă de zarzavat cu bulion, frigărui cu bulion etc.",
                    "image": "bulioncurosiikapia.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Salată de vinete",
                    "description": "Salată de vinete cu ceapă este unul dintre cele mai populare preparate ale verii. Salata se poate servi simplă, cu maioneză sau cu ceapă.",
                    "image": "salata de vinete.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Castraveți murați în oțet",
                    "description": "Castraveți murați în oțet. Rețetă simplă și delicioasă de castraveți murați în oțet.",
                    "image": "castraveti murati.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Castraveți murați în saramură",
                    "description": "Preparați după o rețetă proprie castraveții sunt crocanți și potrivit de acri.",
                    "image": "Castraveti murati in saramura.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Gogonele murate",
                    "description": "Gogonele atent selecționate, puse la saramură.",
                    "image": "Gogonele murate.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Gogoșari murați",
                    "description": "În fiecare borcan am pus rondele de ceapa și de morcov, o foaie mică de dafin, jumătate de linguriță cu boabe de muștar,  jumătate de linguriță cu boabe de coriandru, câteva boabe de piper și câte o bucațică de hrean. ",
                    "image": "gogosari murati.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Ardei copți",
                    "description": "Ardei copți la borcan (gogosari copți la borcan).",
                    "image": "Ardei copti.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Carcasă de porc",
                    "description": "Carne proaspătă de porc. Se poate tăia și la comandă.",
                    "image": "porc2.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Carne de porc",
                    "description": "Carne proaspătă de porc. Se poate tăia și la comandă.",
                    "image": "carne de porc.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Pulpă de porc",
                    "description": "Pulpă de porc. Se poate tăia și la comandă.",
                    "image": "pulpa de porc.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Carne de porc(sferturi)",
                    "description": "Sfert anterior cu guşă. Se poate tăia și la comandă.",
                    "image": "Sfert anterior cu gusă.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Carne de porc(sferturi)",
                    "description": "Sfert anterior fără fleică. Se poate tăia și la comandă.",
                    "image": "Sfert anterior fara fleica.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Șorici de porc",
                    "description": "Șorici proaspăt de porc. Sunați pentru a întreba dacă avem în stoc.",
                    "image": "sorici.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Carne de vită(carcasă)",
                    "description": "Carne proaspătă de vită, carcasă sau sferturi. Se poate tăia și la comandă.",
                    "image": "carne de vita (carcasa).jpg",
                    "price" : 9.9
                },
                {
                    "name": "Mușchi de vită",
                    "description": "Este tăiat din mușchiul vitei și este cea mai apreciată carne de către iubitorii de vită.",
                    "image": "Muschi vita.jpg",
                    "price" : 9.9
                },
                {
                    "name": "Carne de vită",
                    "description": "Carne proaspătă de vită. Se poate tăia și la comandă.",
                    "image": "vita.jpg",
                    "price" : 9.9
                }
                //{
                //    "name": "",
                //    "description": "",
                //    "image": "",
                //    "price" : 9.9
                //},
            ];

        return products;
    };

    Database.get_contact_info = function() {
        var contact_info = {
            "first_name": "Stefania Alina",
            "last_name": " TO DO",
            "phone_number": "0764527716",
            "availability": "24/7",
            "availability_big": "24 de ore pe zi, 7 zile pe săptămână"
        };

        return contact_info;
    };

    Database.get_site_info= function() {
        var site_info = {
            "name" : "Mâncare sănătoasă"
        };

        return site_info;
    };


    return Database;

});