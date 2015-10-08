farmApp.controller('mainControl', ['$scope', '$route', '$location', 'Database', function($scope, $route, $location, Database) {

    $scope.is_initialized = false;
    $scope.contact_info = [];
    $scope.site_info = [];

    $scope.Init = function() {
        $scope.contact_info = Database.get_contact_info();
        $scope.is_initialized = true;
        $scope.site_info = Database.get_site_info();
    };

    $scope.current_page = function () {
        return $location.path().slice(1);
    };

    $scope.openInfo = function(id) {
    };

}]);
