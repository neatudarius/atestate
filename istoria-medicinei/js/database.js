var Database = angular.module('Database', []);
Database.factory('Database', function() {

     Database.get_contact_info = function() {
        var contact_info = {
            "student": "Stan Miruna Ioana",
            "phone_number": "0785878797",
            "email" : "miruna.stan@yahoo.com",
            "highschool":"Colegiul National “Anastasescu”",
            "adress" : "Rosiorii de Vede, jud. Teleorman",
            "teacher": "Ștefan Cătălina"
        };

        return contact_info;
    };

    Database.get_site_info= function() {
        var site_info = {
            "name" : "Istoria medicinei"
        };

        return site_info;
    };


    return Database;

});