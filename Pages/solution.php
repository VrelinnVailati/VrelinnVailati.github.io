<!doctype HTML>

<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta http-equiv="X-UA-Compatible" content="ie=edge">
        <link href="css/bootstrap.css" rel="stylesheet" type="text/css">
        <link rel="stylesheet" href="css/cover.css" type="text/css"> 
        <title>Programa que resuelve la Ecuación Diferencial Linear </title>
    </head>
    <body class="text-center">
        <div class="d-flex w-100 h-100 p-3 mx-auto flex-column">
            <header class="masthead mb-auto">
                <div class="inner">
                    <nav class="nav nav-masthead justify-content-center">
                        <a class="nav-link active disabled" href="index.html">Página inicial</a>
                        <a class="nav-link" href="Pages/information.html">Información</a>
                    </nav>
                </div>
            </header>
            <h1 class="cover-heading">Programa que resuelve la Ecuación Diferencial Linear Homogénea de Segundo Grado con Coeficientes Constantes</h1>
            <div class="mx-auto">
                <form action="Pages/solution.php" class="form-inline">
                    <input type="number" class="form-control mb-2 mr-sm-2" id="firstMemberVariable" placeholder="0">
                    <label style="font-size: larger;" for="firstMemberVariable"><strong>y'' +</strong></label>
                    <input type="number" class="form-control mb-2 ml-2 mr-sm-2" id="secondMemberVariable" placeholder="0">
                    <label style="font-size: larger;" for="firstMemberVariable"><strong>y' +</strong></label>
                    <input type="number" class="form-control mb-2 ml-2 mr-sm-2" id="thirdMemberVariable" placeholder="0">
                    <label style="font-size: larger;" for="firstMemberVariable"><strong>y = 0</strong></label>
                    <button type="submit" class="form-control ml-3 btn btn-outline-light">Resolver</button>
                </form>
            </div>
            <footer class="mastfoot mt-auto">
                <div class="inner">
                    <p>
                        Página hecha por Gómez Hernández Israel Yoltic
                    </p>
                </div>
            </footer>
        </div>
    </body>
</html>
