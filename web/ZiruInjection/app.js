const express = require('express');
const bodyParser = require('body-parser');
const sqlite3 = require('sqlite3').verbose();
const path = require('path');

const app = express();
app.use(bodyParser.urlencoded({ extended: true }));
require('dotenv').config();

const db = new sqlite3.Database(':memory:');
db.serialize(() => {
  db.run(
    `CREATE TABLE users (id INTEGER PRIMARY KEY, username TEXT, password TEXT)`
  );
  db.run(`INSERT INTO users (username, password) VALUES ('admin', 'adminhehehe')`);

  db.run(
    `CREATE TABLE ziruflags (id INTEGER PRIMARY KEY, flagsggboys TEXT)`
  );
  db.run(`INSERT INTO ziruflags (flagsggboys) VALUES ('${process.env.FLAG}')`);
});

app.get('/', (req, res) => {
  res.send(`
    <!DOCTYPE html>
    <html lang="en">
    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>SQLi Challenge</title>
      <style>
        body {
          font-family: 'Arial', sans-serif;
          background: linear-gradient(135deg, #6a11cb, #2575fc);
          color: #fff;
          text-align: center;
          margin: 0;
          padding: 0;
          display: flex;
          justify-content: center;
          align-items: center;
          height: 100vh;
          overflow: hidden;
        }

        h1 {
          font-size: 3rem;
          margin-bottom: 10px;
        }

        p {
          font-size: 1.2rem;
          margin-bottom: 30px;
        }

        form {
          background: rgba(255, 255, 255, 0.1);
          padding: 20px 30px;
          border-radius: 10px;
          box-shadow: 0 4px 15px rgba(0, 0, 0, 0.2);
          backdrop-filter: blur(10px);
          width: 100%;
          max-width: 400px;
        }

        input[type="text"], input[type="password"] {
          width: 100%;
          padding: 12px;
          margin-bottom: 15px;
          border: 1px solid rgba(255, 255, 255, 0.2);
          border-radius: 5px;
          background: rgba(255, 255, 255, 0.1);
          color: #fff;
          font-size: 1rem;
          outline: none;
          transition: 0.3s ease;
        }

        input[type="text"]:focus, input[type="password"]:focus {
          border-color: #fff;
          background: rgba(255, 255, 255, 0.2);
        }

        button {
          width: 100%;
          padding: 12px;
          font-size: 1rem;
          font-weight: bold;
          color: #fff;
          background: #4e54c8;
          border: none;
          border-radius: 5px;
          cursor: pointer;
          transition: 0.3s ease;
        }

        button:hover {
          background: #6a11cb;
        }
      </style>
    </head>
    <body>
      <div>
        <h1>Ziru Injection</h1>
        <p>Prove your worth!!!</p>
        <form method="POST" action="/login">
          <input type="text" name="username" placeholder="Username" required>
          <input type="password" name="password" placeholder="Password" required>
          <button type="submit">Login</button>
        </form>
      </div>
    </body>
    </html>
  `);
});


app.post('/login', (req, res) => {
  const { username, password } = req.body;

  const query = `SELECT * FROM users WHERE username = '${username}' AND password = '${password}'`;
  console.log('Executing query:', query);

  db.get(query, (err, row) => {
    if (err) {
      return res.send(err.message);
    }

    if (row) {
      if (!row.username?.includes('CIU')) {
        return res.send('<h1>Loh flagnya mana?</h1>');
      }
      res.send(`<h1>Welcome, ${row.username}!</h1>`);
    } else {
      res.send('<h1>Invalid username or password!</h1>');
    }
  });
});


app.listen(3000, () => {
  console.log('SQLi Challenge is running on http://localhost:3000');
});
