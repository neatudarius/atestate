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


    $routeProvider.when('/legende', {
        templateUrl: 'partials/.html'
    });

    $routeProvider.when('/clasamente', {
        templateUrl: 'partials/.html'
    });

    $routeProvider.when('/contact', {
        templateUrl: 'partials/contact.html'
    });

    $routeProvider .otherwise({
        redirectTo: '/404'
    });

});