var store = {
    fileds:['yearcode', 'yeardesc'],
    data:function(){
        var year = new Date().getFullYear();
        var data = new Array();
        for(var i = 0; i < 6; i++)
        {
            data[i] = {
                yearcode: (year + i).toString(),
                yeardesc: (year + i).toString()
            }
        }
        return data;
    }()
}

console.log(store.data)