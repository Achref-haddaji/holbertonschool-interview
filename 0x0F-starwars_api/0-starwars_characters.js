#!/usr/bin/node

// Script that prints all characters of a Star Wars movie.

const args = process.argv.slice(2);
// Check if there are enough command line arguments
if (args < 1) {
  console.log('Error');
  process.exit(1);
}

// Extract the episode number from command line argument
const episode = args[0];

const url = 'https://swapi-api.hbtn.io/api/films/' + episode;

// Require the 'request' module for making HTTP requests

const request = require('request');
let characters = [];
request(url, (err, resp, body) => {
  if (err || resp.statusCode !== 200) console.log(err);
  else characters = JSON.parse(body).characters;

  // Get the number of characters
  const size = Object.keys(characters).length;
  const array = Array(size).fill();
  let data = 0;
  for (let i = 0; i < size; i++) {
    request(characters[i], (erro, respo, bodys) => {
      if (erro || respo.statusCode !== 200) console.log(erro);
      else {
        array[i] = JSON.parse(bodys).name;

        data++;
      }
	  // If data for all characters retrieved
      if (data === size) {
        for (let j = 0; j < size; j++) {
			 // Print character names
			 
          console.log(array[j]);
        }
      }
    });
  }
});
