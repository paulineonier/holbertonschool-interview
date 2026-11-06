```
# Star Wars API - Characters Script

## Description
This project contains a Node.js script that retrieves and displays all character names from a specific Star Wars movie in their original order, using the Star Wars API (SWAPI) and the `request` module.

The script preserves the exact sequence of the `characters` array returned by the `/films/` endpoint, even though requests are executed asynchronously.

## Prerequisites
- **Node.js**: v14.x or higher (tested on macOS and Linux)
- **npm**: Node Package Manager

## Installation

1. Clone this repository:
   ```bash
   git clone <your-repository-url>
   cd starwars_api
```

1.  Install dependencies (`request` module):
    
    Bash
    
    ```
    npm install request
    ```
    
2.  Make the script executable:
    
    Bash
    
    ```
    chmod +x 0-starwars_characters.js
    ```
    

## Usage

Run the script by passing the **Movie ID** (from 1 to 6) as the first positional argument:

Bash

```
./0-starwars_characters.js <Movie_ID>
```

Alternatively, you can run it directly with Node:

Bash

```
node 0-starwars_characters.js <Movie_ID>
```

### Movie ID Reference

| ID | Movie Title |
| --- | --- |
| 1 | A New Hope |
| 2 | The Empire Strikes Back |
| 3 | Return of the Jedi |
| 4 | The Phantom Menace |
| 5 | Attack of the Clones |
| 6 | Revenge of the Sith |

## Example Output

Executing the script for Movie ID `3` (_Return of the Jedi_):

Bash

```
$ ./0-starwars_characters.js 3
Luke Skywalker
C-3PO
R2-D2
Darth Vader
Leia Organa
Obi-Wan Kenobi
Chewbacca
Han Solo
Jabba Desilijic Tiure
Wedge Antilles
Yoda
Palpatine
Boba Fett
Lando Calrissian
Ackbar
Mon Mothma
Arvel Crynyd
Wicket Systri Warrick
Nien Nunb
Bib Fortuna
```

## Technical Implementation Details

-   **Shebang**: `#!/usr/bin/env node` for cross-platform execution (macOS & Linux).
    
-   **Asynchronous Order Preservation**: Uses `Promise.all()` over mapped `request` calls to ensure character names print in the exact index order specified in the API response, regardless of network response delays.
    
-   **API Endpoint**: Uses `https://swapi-api.alx-tools.com/api/films/:id/`