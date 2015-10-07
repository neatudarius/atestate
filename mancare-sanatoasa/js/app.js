var farmApp = angular.module('farmApp', ['ngRoute', 'Database']);

farmApp.filter('capitalize', function() {
    return function(input, scope) {
        if (input!=null)
            input = input.toLowerCase();
        return input.substring(0,1).toUpperCase()+input.substring(1);
    }
});

farmApp.filter('divthree', function() {
    return function(input) {
        if( input%3==0)
            return input;
        return input + (3-input%3);
    }
});

farmApp.filter('excerpt', function() {
    return function(input, count) {
        if(count==undefined || isNaN(count) || count < 0) {
            count = 50;
        }
        if(input!=undefined)
            return input.substr(0, count);
        return input;
    }
});