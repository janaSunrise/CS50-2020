let counter = 0;

function increment()
{
    counter++;
    document.querySelector("#counter").innerHTML = counter;
}
function decrement()
{
    counter--;
    document.querySelector("#counter").innerHTML = counter;
}

function reset()
{
    counter = 0;
    document.querySelector("#counter").innerHTML = counter;
}

function greet()
{
    let name = document.querySelector('#name').value;
    if (name === '')
    {
        name = 'world';
    }
    alert('Hello, ' + name + '!');
}

let body = document.querySelector('body');
            document.querySelector('#red').onclick = function() {
                body.style.backgroundColor = 'red';
            }
            document.querySelector('#green').onclick = function() {
                body.style.backgroundColor = 'green';
            }
            document.querySelector('#blue').onclick = function() {
                body.style.backgroundColor = 'blue';
            }

function blink()
{
    let body = document.querySelector('h1');
    if (body.style.visibility === 'hidden')
    {
        body.style.visibility = 'visible';
    }
    else
    {
        body.style.visibility = 'hidden';
    }

}

// Blink every 550ms
window.setInterval(blink, 550);