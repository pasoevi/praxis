let wordsToIgnore = ["the", "of", "in", "from", "by", "with", "and", "or", "for", "to", "at", "a"];

function acronymize(words) {
    let acronym = "";
    words.split('-').forEach(function(el) {
        if (!wordsToIgnore.includes(el)) {
            acronym += el.charAt(0).toUpperCase();
        }
    });

    return acronym;
}

function generateBC(url, separator) {
    let parts = url.replace(/.*:\/\//g, "").split('/');
    let middle, last;

    if (!/index\.[^/.]+$/.test(parts[parts.length - 1])) {
        middle = parts.slice(1, -1);
        last = parts[parts.length - 1];
    } else {
        middle = parts.slice(1, -2);
        last = parts[parts.length - 2];
    }

    let crumbs = [
        '<a href="/">HOME</a>', // root/home
    ];

    console.log(`middle is ${middle}`);
    middle.forEach(function(part, i) {
        let partAcronym = part.toUpperCase().replace(/-/g, ' ');
        if (part.length > 30) {
            partAcronym = acronymize(part);
        }
        crumbs.push(`<a href="/${middle.slice(0, i + 1).join('/')}/">${partAcronym.toUpperCase()}</a>`);
    });

    if (middle.length > 0) {
        console.log(`last is ${last}`);
        let lastAcronym = last.toUpperCase().replace(/-/g, ' ');
        if (last.length > 30) {
            lastAcronym = acronymize(last);
        }
        crumbs.push(`<span class="active">${lastAcronym.replace(/\.[^/.]+$/, "").split('?')[0].toUpperCase()}</span>`); // last element
    }
    return crumbs.join(separator);
}

// console.log(generateBC("mysite.com/pictures/holidays.html", " : "));
// console.log(generateBC("www.microsoft.com/important/confidential/docs/index.htm#top", " * "));
// console.log(generateBC("mysite.com/very-long-url-to-make-a-silly-yet-meaningful-example/example.asp", " > "));
// console.log(generateBC("www.very-long-site_name-to-make-a-silly-yet-meaningful-example.com/users/giacomo-sorbi", " + "));
// console.log(generateBC('http://twitter.de/kamehameha-of-with-meningitis-bladder-for-with-insider/games/app/games#bottom', ' : '));
// console.log(generateBC('http://www.github.com/by-or-biotechnology-uber-insider-the-surfer-from-and-uber/or-bladder-and-of-skin-research-kamehameha-by-diplomatic', ' # '));
// console.log(generateBC('https://google.ca/uber-surfer-and-from-of-immunity-cauterization/most-downloaded/research-insider-the-from-uber-at-by-research/index.php', ' : '));
console.log(generateBC('http://google.ca?rank=recent_first&hide=sold', ' # '));