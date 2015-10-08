farmApp.config( function( $routeProvider, $locationProvider ) {

    $routeProvider.when('/', {
        templateUrl: 'partials/acasa.html'
    });

    $routeProvider.when('/acasa', {
        templateUrl: 'partials/acasa.html'
    });

    $routeProvider.when('/contact', {
        templateUrl: 'partials/contact.html'
    });

    $routeProvider.when('/nastase', {
        templateUrl: 'partials/nastase.html'
    });

    $routeProvider .otherwise({
        redirectTo: '/404'
    });

});