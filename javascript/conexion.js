import { initializeApp } from 'https://www.gstatic.com/firebasejs/10.9.0/firebase-app.js';
import { getDatabase, ref, onValue } from 'https://www.gstatic.com/firebasejs/10.9.0/firebase-database.js';

const firebaseConfig = {
    apiKey: "AIzaSyAdREvpKzqBRQqR5IJFm9BquBoNpS_fvBc",
    authDomain: "aquacontrol-d620c.firebaseapp.com",
    databaseURL: "https://aquacontrol-d620c-default-rtdb.firebaseio.com",
    projectId: "aquacontrol-d620c",
    storageBucket: "aquacontrol-d620c.appspot.com",
    messagingSenderId: "420609314714",
    appId: "1:420609314714:web:d6611f74ddc2d83eaab423"
};


const app = initializeApp(firebaseConfig);



const db = getDatabase(app);
const dbRef = ref(db, '/Cantidadagua/Cantagua');
onValue(dbRef, (snapshot) => {
    if (snapshot.exists()) {
        const data = snapshot.val();
        console.log("el porcentaje es de: ", data);
        function toggleDivs(valor) {
            const div1 = document.getElementById('div1');
            const div2 = document.getElementById('div2');
            const div3 = document.getElementById('div3');
            const div4 = document.getElementById('div4');
            const div5 = document.getElementById('div5');
            const div6 = document.getElementById('div6');
            const div7 = document.getElementById('div7');
            const div8 = document.getElementById('div8');
            const div9 = document.getElementById('div9');
            const div10 = document.getElementById('div10');
            // Ocultar todos los divs
            div1.style.display = 'none';
            div2.style.display = 'none';
            div3.style.display = 'none';
            div4.style.display = 'none';
            div5.style.display = 'none';
            div6.style.display = 'none';
            div7.style.display = 'none';
            div8.style.display = 'none';
            div9.style.display = 'none';
            div10.style.display = 'none';

            // Mostrar div1 si el valor es 10
            if (valor === 10) {
                div1.style.display = 'block';
            }

            // Mostrar div2 y div3 si el valor es 20
            if (valor === 20) {
                div1.style.display = 'block';
                div2.style.display = 'block';
            }

            if (valor === 30) {
                div1.style.display = 'block';
                div2.style.display = 'block';
                div3.style.display = 'block';
            }

            if (valor === 40) {
                div1.style.display = 'block';
                div2.style.display = 'block';
                div3.style.display = 'block';
                div4.style.display = 'block';
            }

            if (valor === 50) {
                div1.style.display = 'block';
                div2.style.display = 'block';
                div3.style.display = 'block';
                div4.style.display = 'block';
                div5.style.display = 'block';
            }

            if (valor === 60) {
                div1.style.display = 'block';
                div2.style.display = 'block';
                div3.style.display = 'block';
                div4.style.display = 'block';
                div5.style.display = 'block';
                div6.style.display = 'block';
            }

            if (valor === 70) {
                div1.style.display = 'block';
                div2.style.display = 'block';
                div3.style.display = 'block';
                div4.style.display = 'block';
                div5.style.display = 'block';
                div6.style.display = 'block';
                div7.style.display = 'block';
            }

            if (valor === 80) {
                div1.style.display = 'block';
                div2.style.display = 'block';
                div3.style.display = 'block';
                div4.style.display = 'block';
                div5.style.display = 'block';
                div6.style.display = 'block';
                div7.style.display = 'block';
                div8.style.display = 'block';
            }

            if (valor === 90) {
                div1.style.display = 'block';
                div2.style.display = 'block';
                div3.style.display = 'block';
                div4.style.display = 'block';
                div5.style.display = 'block';
                div6.style.display = 'block';
                div7.style.display = 'block';
                div8.style.display = 'block';
                div9.style.display = 'block';
            }

            if (valor === 100) {
                div1.style.display = 'block';
                div2.style.display = 'block';
                div3.style.display = 'block';
                div4.style.display = 'block';
                div5.style.display = 'block';
                div6.style.display = 'block';
                div7.style.display = 'block';
                div8.style.display = 'block';
                div9.style.display = 'block';
                div10.style.display = 'block';
            }
        }

        // Llamar a la función toggleDivs con el valor obtenido de Firebase
        toggleDivs(data);
    } else {
        console.log("No se encontraron datos en la ruta especificada.");
    }
});

