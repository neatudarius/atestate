farmApp.controller('mainControl', ['$scope', '$route', '$location', 'Database', function($scope, $route, $location, Database) {

    $scope.is_initialized = false;
    $scope.product_list = [];
    $scope.contact_info = [];
    $scope.current_product = [];
    $scope.site_info = [];
    $scope.last_expanded_id = -1;

    $scope.Init = function() {
        $scope.product_list = Database.get_products();
        $scope.contact_info = Database.get_contact_info();
        $scope.is_initialized = true;
        $scope.site_info = Database.get_site_info();
    };

    $scope.current_page = function () {
        return $location.path().slice(1);
    };

    $scope.openInfo = function(id) {
        $scope.current_product = $scope.product_list[id-1];
        if( id%3!=0)
            xid = id + (3-id%3);
        else
            xid = id;

        var crtCollapse = $('#info' + xid);
        if( id == $scope.last_expanded_id ) {
            crtCollapse.collapse('hide');
            $scope.last_expanded_id = -1;
            return;
        }

        $scope.last_expanded_id = id;

        //hide everything else
        var collapseCnt = $scope.product_list.length;
        if( collapseCnt % 3 != 0)
            collapseCnt = collapseCnt + 3;

        for( i=0; i<=collapseCnt; i+=3)
            if( xid != i )
                $('#info' + i).collapse('hide');

        //the current one
        crtCollapse.collapse('show');
    };

}]);
