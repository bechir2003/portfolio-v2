<html>


<?php
   require ('../../../config.php');
   include ('../../../controller/user_management/user_control.php');
   $db=config::getConnexion();
   $res=User_control::show_users($db);
   $id=$_POST['id_user'];
   foreach($res as $t){
       if($t['user_id']==$id){
           $first_name=$t['first_name'];
           $last_name=$t['last_name'];
           $email=$t['email'];
           $role=$t['role'];
           $password=$t['password'];
           break;
       }
   }
?>
<pre>       
</pre>
<div class="contactform" >
   <div id="edited"></div>
   <h3>edit information</h3>
 
      <div class="inputboite">
         <input type="text" placeholder="first_name" id="id" value="<?php echo$id?>" hidden>
      </div>
      <div class="inputboite">
         <input type="text" placeholder="first_name" id="first_name" value="<?php echo$first_name?>" >
      </div>
      <div class="inputboite">
         <input type="text" placeholder="last_name" id="last_name" value="<?php echo$last_name?>" >
      </div>
      <div class="inputboite">
         <input type="text" placeholder="email" id="email" value="<?php echo$email?>">
      </div>
      <div class="inputboite">
        <select name="" id="role">
         <option value="">role</option>
         <option value="PATIENT">PATIENT</option>
         <option value="ART THERAPIST">ART THERAPIST</option>
         <option value="Administrator">Administrator</option>
        </select>
      </div>
      <div class="inputboite">
         <input type="password" placeholder="password" id="password" value="<?php echo$password?>">
      </div>
      <div class="inputboite">
         <button class="btn-reserve" onclick="return validateRegistrationForm()" >confirm</button>
         <div id="erreur" style="color: red;" ></div>
      </div> 
      
   
</div>
 
<script>
   function updateuser(){
      $(document).ready(function(){
         var id=document.getElementById('id').value;
         var first_name=document.getElementById('first_name').value;
         var last_name=document.getElementById('last_name').value;
         var email=document.getElementById('email').value;
         var selectElement=document.getElementById('role');
         var role = selectElement.value;
         var password=document.getElementById('password').value;
         $("#container").load("update_user.php",{
               id_user: id,
               first_name: first_name,
               last_name: last_name,
               email: email,
               role: role,
               password: password
         });
      });
   }
   
   function validateRegistrationForm() {
            var firstName = document.getElementById('first_name').value;
            var lastName = document.getElementById('last_name').value;
            var role = document.getElementById('role').value;
            var email = document.getElementById('email').value;
            var password = document.getElementById('password').value;
    
            // Check if required fields are empty
            if (firstName.length== 0 || lastName.length== 0   || password.length== 0) {
                document.getElementById('erreur').innerHTML="Please fill in all required fields"
                return false; // Prevent form submission
            }
    
            // Check if a valid email address is entered
            var emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
            if (!emailRegex.test(email)) {
                document.getElementById('erreur').innerHTML="Please enter a valid email address."
                return false; // Prevent form submission
            }
    
            // You can add more specific validation if needed
    
            // If all validations pass, the form will be submitted
            updateuser();
            return true;
        }
</script>
 
</html>