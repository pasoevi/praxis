def queensproblem(series, spalten):
    if series <= 0:
        return [[]] # keine Dame zu setzen; leeres Brett ist Lösung
    else:
        return eine_dame_dazu(series - 1, spalten, queensproblem(series - 1, spalten))
 
def eine_dame_dazu(neue_reihe, spalten, vorherige_loesungen):
    neue_loesungen = []
    for loesung in vorherige_loesungen:

        for neue_spalte in range(spalten):

            if kein_konflikt(neue_reihe, neue_spalte, loesung):

                neue_loesungen.append(loesung + [neue_spalte])
    return neue_loesungen
 
def kein_konflikt(neue_reihe, neue_spalte, loesung):
    for reihe in range(neue_reihe):
        if loesung[reihe]         == neue_spalte or loesung[reihe] + reihe == neue_spalte + neue_reihe or loesung[reihe] - reihe == neue_spalte - neue_reihe:
                return False
    return True
 
for loesung in queensproblem(8, 8):
    print(loesung)

