
function toggleMenu() {
    var navLinks = document.getElementById("nav-links");
    if (navLinks.style.display === "block") {
        navLinks.style.display = "none";
    } else {
        navLinks.style.display = "block";
    }
};

function toggleModo() {
    var body = document.body;
    var iconoModo = document.getElementById("iconoModo");
    var modoBtn = document.getElementById("modoBtn");
    if (body.classList.contains("modo-oscuro")) {
        modoBtn.style.borderColor = "#333";
        modoBtn.style.Color = "#f0f0f0";
        body.classList.remove("modo-oscuro");
        iconoModo.classList.remove("fa-moon");
        iconoModo.classList.add("fa-sun");
    } else {
        modoBtn.style.borderColor = "#f0f0f0";
        modoBtn.style.Color = "#333";
        modoBtn.classList.remove("modoBtn-claro");
        body.classList.add("modo-oscuro");
        iconoModo.classList.remove("fa-sun");
        iconoModo.classList.add("fa-moon");
    }
};


function mostrarFechaHora() {
    const spanHora = document.getElementById('hora');
    const spanDia = document.getElementById('dia');
    const spanFecha = document.getElementById('fecha');

    const fechaHoraActual = new Date();
    const optionsHora = { hour: 'numeric', minute: 'numeric', second: 'numeric' };
    const optionsDia = { weekday: 'long' };
    const optionsFecha = { year: 'numeric', month: 'long', day: 'numeric' };

    spanHora.textContent = fechaHoraActual.toLocaleTimeString('es-GT', optionsHora);
    spanDia.textContent = fechaHoraActual.toLocaleDateString('es-GT', optionsDia);
    spanFecha.textContent = fechaHoraActual.toLocaleDateString('es-GT', optionsFecha);
}

setInterval(mostrarFechaHora,1000);