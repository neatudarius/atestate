farmApp.config( function( $routeProvider, $locationProvider ) {

    $routeProvider.when('/', {
        templateUrl: 'partials/acasa.html'
    });

    $routeProvider.when('/acasa', {
        templateUrl: 'partials/acasa.html'
    });

    $routeProvider.when('/produse', {
        templateUrl: 'partials/produse.html'
    });

    $routeProvider.when('/contact', {
        templateUrl: 'partials/contact.html'
    });

    $routeProvider.when('/despre', {
        templateUrl: 'partials/despre.html'
    });

    $routeProvider.when('/specialitatea-casei', {
        templateUrl: 'partials/specialitatea-casei.html'
    });

    $routeProvider.when('/teleorman', {
        templateUrl: 'partials/teleorman.html'
    });

    $routeProvider .otherwise({
        redirectTo: '/404'
    });


});