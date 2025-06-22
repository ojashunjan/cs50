const button = document.querySelectorAll(".choice");

const q1answer = document.getElementById("part1-feedback");

button.forEach(button => {
    button.addEventListener("click", () => {
        button.forEach(btn => btn.disabled = true);

        const right = button.getAttribute("data-correct") === "true";
        if (right) {

            button.classList.add("correct");
            q1answer.textContent = "Correct!";

        }
        else {

            button.classList.add("incorrect");
            q1answer.textContent = "Incorrect try again please :)"
        }
    });
});

const input = document.getElementById("free-response");

const sub = document.getElementById("submit-answer");

const part2answer = document.getElementById("part2-feedback");

submit.addEventListener("click, () => {

    const answer = input.value.trim().toLowerCase();

    if (answer == "Russia") {

        input.classList.remove("incorrect");

        input.classList.add("correct);

        part2answer.textContent = "Correct!";


    }

    else {

        input.classList.remove("correct");

        input.classList.add("incorrect");

        part2answer.textContent = "Incorrect try again";


    }

});
