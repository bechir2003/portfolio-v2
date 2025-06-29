
<?php
    session_start();
    require('../../../config.php');
    $db = config::getConnexion();
    $query = "SELECT * FROM temoignages";
    $res = $db->query($query);
    if($_SESSION['loggedIn']==1){
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="../assets/js/user.js" ></script>
    <link rel="stylesheet" href="../assets/edit_user.css">
    <title>Users Table</title>
    <style>
        
        table {
            border: 2px;
            width: 100%;
            margin: 0 auto; /* Center the table */
            background-color: #fff; /* Set the background color to white */
        }

        table, th, td {
            border: 1px solid #ddd;
        }

        th, td {
            padding: 8px;
            text-align: left;
        }
        .scrollable-table {
          max-height: 400px; /* ajustez la hauteur maximale selon vos besoins */
          overflow-y: auto;
        }
    </style>
</head>
<body>
<div class="scrollable-table">
    <div  class='show' id='container'>
        <table>
        <th><label for="search">Search:</label>
        <input type="text" id="search" onkeyup="searchFunction()" placeholder="Enter search term..."></th>
            <tr>
                <td>first_name</td>
                <td>last_name</td>
                <td>email</td>
                <td>comment</td>
            </tr>

            <?php
            foreach ($res as $t) {
                echo "
                
                <tr>
                    <td>" . $t['first_name'] . "</td>
                    <td>" . $t['last_name'] . "</td>
                    <td>" . $t['email'] . "</td>
                    <td>" . $t['message']  . "</td>
                    <td><button onclick=\"deletComment(" . $t['id_tem'] . ")\">Delete</button></td>
                </tr>";
            }
            ?>
        </table>    
    </div>
    </div>
    
</body>
<script>
  function searchFunction() {

    var input, filter, table, tr, td, i, txtValue;
    input = document.getElementById("search");
    filter = input.value.toUpperCase();
   
    table = document.querySelector(".show"); 
    tr = table.getElementsByTagName("tr");

    
    for (i = 2; i < tr.length; i++) {
      
      var rowContainsSearchTerm = false;
      for (var j = 0; j < tr[i].cells.length; j++) {
        td = tr[i].getElementsByTagName("td")[j];
        if (td) {
          txtValue = td.textContent || td.innerText;
          if (txtValue.toUpperCase().indexOf(filter) > -1) {
            rowContainsSearchTerm = true;
            break; 
          }
        }
      }

      if (rowContainsSearchTerm) {
        tr[i].style.display = "";
      } else {
        tr[i].style.display = "none";
      }
    }
  }
</script>
<script>

    function deletComment(id){
        $(document).ready(function(){
            var confirmed = confirm('Are you sure you want to delete this COMMENT?');
            if (confirmed) {
                $("#container").load("delete_comments.php",{
                    tem_id: id
                });
            }
            else{
                alert('Deletion canceled');
            }
        });
    }

</script>
</html>
<?php
}else{
?>
<script>
  window.location.reload(true);
</script>
<?php
}
?>