const express = require('express');
const bodyParser = require('body-parser');
const pug = require('pug');
const fs = require('fs');
const path = require('path');

const app = express();
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

require('dotenv').config();

const blacklist = ['require', 'fs', 'readFileSync', 'process', 'constructor', '_load', 'global'];

const flag = process.env.FLAG || 'CIU2025{K4MU_H3B4T}';
const flagFileName = process.env.FLAG_FILE || `${Math.random().toString(36).substring(2, 8)}.txt`;
fs.writeFileSync(path.join(__dirname, flagFileName), flag);

app.get('/', (req, res) => {
  res.send(`
    <!DOCTYPE html>
    <html lang="en">
    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Pground</title>
      <style>
        body {
          font-family: Arial, sans-serif;
          background-color: #f4f4f9;
          color: #333;
          margin: 0;
          padding: 0;
          display: flex;
          justify-content: center;
          align-items: center;
          flex-direction: column;
          min-height: 100vh;
        }
        h1 {
          color: #5d5fef;
        }
        form {
          margin-bottom: 20px;
        }
        textarea {
          width: 300px;
          height: 100px;
          padding: 10px;
          font-size: 16px;
          border: 1px solid #ccc;
          border-radius: 5px;
          resize: none;
        }
        button {
          padding: 10px 20px;
          font-size: 16px;
          background-color: #5d5fef;
          color: white;
          border: none;
          border-radius: 5px;
          cursor: pointer;
        }
        button:hover {
          background-color: #4b4cd4;
        }
        .output {
          width: 300px;
          background: #fff;
          padding: 15px;
          border: 1px solid #ccc;
          border-radius: 5px;
          box-shadow: 0 0 5px rgba(0, 0, 0, 0.1);
        }
        .error {
          color: red;
        }
      </style>
    </head>
    <body>
      <h1>Welcome to Pground!</h1>
      <p>Submit your text and see the output below!</p>
      <form method="POST" action="/" id="myForm">
        <textarea name="template" placeholder="Enter your text here"></textarea><br>
        <button type="submit">Render</button>
      </form>
      <div class="raw" id="raw"></div>
      <div class="output" id="output"></div>
      <div class="error" id="error"></div>

      <script>
        const form = document.getElementById('myForm');
        const output = document.getElementById('output');
        const error = document.getElementById('error');

        form.addEventListener('submit', async (event) => {
          event.preventDefault();
          const response = await fetch('/render', {
            method: 'POST',
            headers: {
              'Content-Type': 'application/x-www-form-urlencoded',
            },
            body: new URLSearchParams(new FormData(form)),
          });
          const text = await response.text();

          raw.innerHTML = 'Your input: ' + form.template.value;
          if (response.ok) {
            output.innerHTML = text;
            error.textContent = '';
          } else {
            error.textContent = text;
            output.innerHTML = '';
          }
        });
      </script>
    </body>
    </html>
  `);
});

app.post('/render', (req, res) => {
  const userTemplate = req.body.template;

  for (const word of blacklist) {
    if (userTemplate.includes(word)) {
      return res.status(400).send(`Your input contains a forbidden word: "${word}".`);
    }
  }

  const compiledFunction = pug.compile(userTemplate);
  const html = compiledFunction();
  res.status(200).send(html);
});

app.listen(3000, () => {
  console.log(`Flag is stored in ${flagFileName}`);
});
