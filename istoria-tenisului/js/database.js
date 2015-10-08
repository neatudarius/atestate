var Database = angular.module('Database', []);
Database.factory('Database', function() {

     Database.get_contact_info = function() {
        var contact_info = {
            "first_name": "Gabriela Miruna",
            "last_name": "Măndică",
            "phone_number": "0769485904",
            "email" : "miruna.mandica@yahoo.com"
        };

        return contact_info;
    };

    Database.get_site_info= function() {
        var site_info = {
            "name" : "Istoria tenisului"
        };

        return site_info;
    };


    return Database;

});