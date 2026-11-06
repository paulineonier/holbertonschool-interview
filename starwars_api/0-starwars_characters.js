#!/usr/bin/env node
const request = require('request');

const filmId = process.argv[2];
const url = `https://swapi-api.alx-tools.com/api/films/${filmId}/`;

request(url, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  const filmData = JSON.parse(body);
  const characters = filmData.characters;

  // Tableau pour stocker les promesses dans l'ordre exact des URLs
  const characterPromises = characters.map((characterUrl) => {
    return new Promise((resolve, reject) => {
      request(characterUrl, (err, res, charBody) => {
        if (err) {
          reject(err);
        } else {
          resolve(JSON.parse(charBody).name);
        }
      });
    });
  });

  // Attendre la résolution de toutes les requêtes en conservant l'ordre
  Promise.all(characterPromises)
    .then((names) => {
      names.forEach((name) => console.log(name));
    })
    .catch((err) => console.error(err));
});
