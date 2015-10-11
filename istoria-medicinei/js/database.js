var Database = angular.module('Database', []);
Database.factory('Database', function() {

     Database.get_contact_info = function() {
        var contact_info = {
            "first_name": "Miruna Ioana",
            "last_name": "Stan",
            "phone_number": "TO DO",
            "email" : "TO DO"
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