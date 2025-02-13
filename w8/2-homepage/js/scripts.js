document.addEventListener("DOMContentLoaded", function() {
    //DEBUG
    //console.log("Hello World");

    const url = window.location.pathname;

    const pageName = url.substring(url.lastIndexOf('/') + 1).split('.')[0];

    document.getElementById("breadcrumbs").innerHTML = "<b>Hello! you are in the</b> <b class='rainbow-text'>" + pageName + "</b> <b>page</b>";

    //DEBUG
    //console.log(pageName);

});
