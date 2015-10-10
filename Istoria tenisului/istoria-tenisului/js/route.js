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

    $routeProvider.when('/nastase', {
        templateUrl: 'partials/nastase.html'
    });


    $routeProvider.when('/legende', {
        templateUrl: 'partials/legende.html'
    });

    $routeProvider.when('/clasamente', {
        templateUrl: 'partials/clasamente.html'
    });

    $routeProvider.when('/contact', {
        templateUrl: 'partials/contact.html'
    });

    $routeProvider .otherwise({
        redirectTo: '/404'
    });

});