// ACTIVITY popup
const activity = document.getElementById("activity");
document.getElementById("openActivity").onclick = () => activity.style.display = "flex";
document.getElementById("closeActivity").onclick = () => activity.style.display = "none";

// CONTACT popup
const contactOverlay = document.getElementById("contactOverlay");
document.getElementById("openContact").onclick = () => contactOverlay.style.display = "flex";
document.getElementById("closeContact").onclick = () => contactOverlay.style.display = "none";

// LEARNINGS popup
const learningsOverlay = document.getElementById("learningsOverlay");
document.getElementById("openLearnings").onclick = () => learningsOverlay.style.display = "flex";
document.getElementById("closeLearnings").onclick = () => learningsOverlay.style.display = "none";

// PROJECT popup
const projectOverlay = document.getElementById("projectOverlay");
document.getElementById("openProject").onclick = () => projectOverlay.style.display = "flex";
document.getElementById("closeProject").onclick = () => projectOverlay.style.display = "none";

// ABOUT popup
const aboutOverlay = document.getElementById("aboutOverlay");
document.getElementById("openAbout").onclick = () => aboutOverlay.style.display = "flex";
document.getElementById("closeAbout").onclick = () => aboutOverlay.style.display = "none";
