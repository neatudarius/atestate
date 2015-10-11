farmApp.config( function( $routeProvider, $locationProvider ) {

    $routeProvider.when('/', {
        templateUrl: 'partials/acasa.html'
    });

    $routeProvider.when('/acasa', {
        templateUrl: 'partials/acasa.html'
    });


    $routeProvider.when('/istorie', {
        templateUrl: 'partials/istorie.html'
    });

    $routeProvider.when('/date-importante', {
        templateUrl: 'partials/date-importante.html'
    });


    $routeProvider.when('/victor-babes', {
        templateUrl: 'partials/victor-babes.html'
    });

    $routeProvider.when('/medicina-in-prezent', {
        templateUrl: 'partials/medicina-in-prezent.html'
    });

    $routeProvider.when('/despre', {
        templateUrl: 'partials/despre.html'
    });

    $routeProvider .otherwise({
        redirectTo: '/404'
    });

});