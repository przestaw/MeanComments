#!python3
import sys
import random
import re

names = ['Ada', 'Adamina', 'Adela', 'Adelajda', 'Adriana', 'Adrianna', 'Agata', 'Agnieszka', 'Aida', 'Alberta',
         'Albertyna', 'Albina', 'Aldona', 'Aleksa', 'Aleksandra', 'Aleksja', 'Alfreda', 'Alicja', 'Alina', 'Alojza',
         'Amalia', 'Amanda', 'Amelia', 'Amina', 'Amira', 'Anastazja', 'Andrea', 'Andrzeja', 'Andżelika', 'Aneta',
         'Angela', 'Angelika', 'Angelina', 'Aniela', 'Anita', 'Anna', 'Antonina', 'Anzelma', 'Apollina', 'Apolonia',
         'Arabella', 'Ariadna', 'Arleta', 'Arnolda', 'Astryda', 'Atena', 'Augusta', 'Augustyna', 'Aurelia', 'Babeta',
         'Balbina', 'Barbara', 'Bartłomieja', 'Beata', 'Beatrycja', 'Beatrycze', 'Beatryksa', 'Benedykta', 'Beniamina',
         'Benigna', 'Berenika', 'Bernarda', 'Bernadeta', 'Berta', 'Betina', 'Bianka', 'Bibiana', 'Blanka', 'Błażena',
         'Bogdana', 'Bogna', 'Boguchwała', 'Bogumiła', 'Bogusława', 'Bojana', 'Bolesława', 'Bona', 'Bożena', 'Bromira',
         'Bronisława', 'Brunhilda', 'Brygida', 'Cecylia', 'Celestyna', 'Celina', 'Cezaria', 'Cezaryna', 'Celestia',
         'Chociemira', 'Chwalisława', 'Ciechosława', 'Ciesława', 'Cinosława', 'Cina', 'Czesława', 'Dajmira', 'Dagna',
         'Dagmara', 'Dalia', 'Dalila', 'Dalmira', 'Damroka', 'Dana', 'Daniela', 'Danisława', 'Danuta', 'Dargomira',
         'Dargosława', 'Daria', 'Dąbrówka', 'Delfina', 'Delia', 'Deresa', 'Desreta', 'Delinda', 'Diana', 'Dilara',
         'Dobiesława', 'Dobrochna', 'Domasława', 'Dominika', 'Donata', 'Dorosława', 'Dorota', 'Dymfna', 'Dyzma',
         'Dżanan', 'Dżamila', 'Dżesika', 'Edeltrauda', 'Edeltruda', 'Edyta', 'Eleonora', 'Eliza', 'Elena', 'Elwira',
         'Elżbieta', 'Elmira', 'Elora', 'Emanuela', 'Emilia', 'Emina', 'Emma', 'Ernesta', 'Ernestyna', 'Eryka',
         'Estera', 'Eugenia', 'Eunika', 'Ewa', 'Ewarysta', 'Ewelina', 'Fabia', 'Faria', 'Fabiana', 'Fabiola', 'Farida',
         'Fatima', 'Fatma', 'Faustyna', 'Fera', 'Felicja', 'Felicjana', 'Felicyta', 'Feliksa', 'Ferdynanda', 'Filipa',
         'Filipina', 'Filomena', 'Flora', 'Florentyna', 'Floriana', 'Franciszka', 'Fryderyka', 'Gabriela', 'Gaja',
         'Genowefa', 'Gerarda', 'Gertruda', 'Gizela', 'Gloria', 'Gniewomira', 'Gracja', 'Gracjana', 'Grażyna', 'Greta',
         'Gryzelda', 'Grzymisława', 'Grzymsława', 'Gustawa', 'Gwidona', 'Hadriana', 'Halina', 'Halszka', 'Hanna',
         'Helena', 'Helga', 'Henrieta', 'Henryka', 'Herma', 'Hermana', 'Hermenegilda', 'Hermina', 'Hestia', 'Hiacynta',
         'Hilaria', 'Hildegarda', 'Hipolita', 'Honorata', 'Hortensja', 'Huberta', 'Ida', 'Idosława', 'Idzia', 'Idalia',
         'Idzisława', 'Iga', 'Ildefonsa', 'Ilga', 'Ilia', 'Iliana', 'Ilona', 'Ilza', 'Inga', 'Inka', 'Ingeborga',
         'Ingryda', 'Irena', 'Iryda', 'Irina', 'Ira', 'Irma', 'Irmina', 'Iwa', 'Iwona', 'Izabela', 'Izolda', 'Izydora',
         'Jadwiga', 'Jagoda', 'Jagna', 'Jana', 'Janina', 'Jarmiła', 'Jaromiła', 'Jaromira', 'Jarosława', 'Jasława',
         'Jaśmina', 'Joachima', 'Joanna', 'Jolanta', 'Jowita', 'Józefa', 'Józefina', 'Judyta', 'Julia', 'Julianna',
         'Julisława', 'Julita', 'Justyna', 'Juta', 'Kaja', 'Kama', 'Kalina', 'Kamila', 'Kamira', 'Karima', 'Karina',
         'Karola', 'Karolina', 'Karyna', 'Katarzyna', 'Kasandra', 'Kazimiera', 'Kiara', 'Kiliana', 'Kinga', 'Kira',
         'Keira', 'Keiria', 'Klara', 'Klarysa', 'Klaudia', 'Klaudyna', 'Klementyna', 'Kleopatra', 'Klotylda',
         'Konstancja', 'Kordula', 'Kornelia', 'Koryna', 'Krystiana', 'Krystyna', 'Krzysztofa', 'Ksawera', 'Ksenia',
         'Kunegunda', 'Kwiatosława', 'Laila', 'Lajla', 'Lana', 'Lara', 'Larisa', 'Larysa', 'Latifa', 'Laura',
         'Laurencja', 'Lea', 'Leka', 'Lejla', 'Lena', 'Leokadia', 'Leona', 'Leonarda', 'Leoncja', 'Leonora', 'Leontyna',
         'Leopolda', 'Letycja', 'Lidia', 'Lila', 'Lisa', 'Ligia', 'Lilia', 'Liliana', 'Lilianna', 'Linda', 'Liwia',
         'Lora', 'Luborada', 'Lucjana', 'Lucjola', 'Lucyna', 'Ludmiła', 'Ludolfa', 'Ludwika', 'Ludwina', 'Luiza',
         'Luna', 'Lilianna', 'Ładana', 'Ładysława', 'Łagoda', 'Łucja', 'Macieja', 'Magda', 'Magdalena', 'Maja', 'Maksa',
         'Maksyma', 'Malina', 'Malwina', 'Małgorzata', 'Manuela', 'Marcela', 'Marcelina', 'Marcjana', 'Marcjanna',
         'Maria', 'Mariam', 'Marianna', 'Marietta', 'Marika', 'Mariola', 'Marlena', 'Marta', 'Martyna', 'Maryja',
         'Maryla', 'Maryna', 'Marzena', 'Matylda', 'Melania', 'Michalina', 'Mieczysława', 'Milena', 'Milomira',
         'Miłosława', 'Miłowita', 'Minerwa', 'Mina', 'Mira', 'Mirabela', 'Miranda', 'Mirela', 'Miriam', 'Mirka',
         'Miroda', 'Mirołada', 'Mirosława', 'Mojmira', 'Mojra', 'Monika', 'Morzana', 'Morzena', 'Nadia', 'Nadzieja',
         'Najmiła', 'Najsława', 'Narcyza', 'Natalia', 'Natasza', 'Nela', 'Nika', 'Nikodema', 'Nikola', 'Nitara',
         'Nikoleta', 'Nina', 'Nira', 'Noemi', 'Nora', 'Norberta', 'Norma', 'Oda', 'Odeta', 'Odyla', 'Ofelia', 'Oksana',
         'Oktawia', 'Olga', 'Olimpia', 'Oliwia', 'Oriana', 'Ota', 'Otylia', 'Ożanna', 'Obina', 'Olena', 'Pabiana',
         'Pamela', 'Patrycja', 'Paula', 'Paulina', 'Pelagia', 'Petra', 'Petronela', 'Petronia', 'Placyda', 'Pola',
         'Polianna', 'Polmira', 'Przemysława', 'Przybysława', 'Rachela', 'Ramona', 'Radmiła', 'Radomiła', 'Radomira',
         'Radosława', 'Rafaela', 'Rajmunda', 'Rajna', 'Raszyda', 'Rebeka', 'Regina', 'Remigia', 'Renata', 'Rejna',
         'Rita', 'Roberta', 'Rodzisława', 'Roksana', 'Roma', 'Romana', 'Romualda', 'Rozalia', 'Rozalinda', 'Rozamunda',
         'Rozetta', 'Rozwita', 'Róża', 'Rudolfina', 'Rut', 'Ruta', 'Ryksa', 'Ryta', 'Ryszarda', 'Sabina', 'Sabrina',
         'Sarina', 'Sarita', 'Safira', 'Safana', 'Salma', 'Saloma', 'Salomea', 'Samanta', 'Samantra', 'Samara',
         'Sandra', 'Sara', 'Semira', 'Sebastiana', 'Selena', 'Selma', 'Serafina', 'Seweryna', 'Sędomira', 'Sędzisława',
         'Sława', 'Sławina', 'Sławomira', 'Sobiesława', 'Sonia', 'Stamira', 'Stanisława', 'Stefania', 'Stela',
         'Stoisława', 'Stella', 'Strzeżymira', 'Subisława', 'Sulima', 'Sulisława', 'Sybilla', 'Sydonia', 'Sylwana',
         'Sylwia', 'Szarlota', 'Szarlin', 'Szarlina', 'Szejma', 'Szymona', 'Świetlana', 'Świętomira', 'Świętosława',
         'Tabita', 'Tacjana', 'Tadea', 'Tamara', 'Tatiana', 'Tekla', 'Telimena', 'Teodora', 'Teodozja', 'Teofila',
         'Teresa', 'Tęgomira', 'Tina', 'Tolisława', 'Tomiła', 'Tomisława', 'Tulimira', 'Tessa', 'Tymora', 'Tyria',
         'Tybita', 'Tybilla', 'Ulana', 'Ulryka', 'Unima', 'Urszula', 'Uta', 'Wacława', 'Walentyna', 'Waleria',
         'Wanda', 'Wanessa', 'Weronika', 'Weridiana', 'Wiara', 'Wiesława', 'Wierzchosława', 'Wiktoria', 'Wiktoryna',
         'Wilhelmina', 'Wincentyna', 'Wioleta', 'Wioletta', 'Wirgilia', 'Wirginia', 'Wisława', 'Witosława',
         'Władysława', 'Włodzimiera', 'Wolimira', 'Wrocisława', 'Zaida', 'Zaira', 'Zdzisława', 'Zefiryna', 'Zenobia',
         'Zenona', 'Zofia', 'Zoja', 'Zuzanna', 'Zwinisława', 'Zygfryda', 'Zygmunta', 'Zyta', 'Żaklina', 'Żaneta',
         'Żanna', 'Żelisława', 'Żużanna', 'Żywia', 'Żywisława', 'Aaron', 'Abdon', 'Abel', 'Abelard', 'Abraham',
         'Achilles', 'Adam', 'Adelard', 'Adnan', 'Adrian', 'Agapit', 'Agaton', 'Agrypin', 'Ajdin', 'Albert', 'Alan',
         'Albin', 'Albrecht', 'Aleks', 'Aleksander', 'Aleksy', 'Alfons', 'Alfred', 'Alojzy', 'Alwin', 'Amadeusz',
         'Ambroży', 'Anastazy', 'Ananiasz', 'Anatol', 'Andrzej', 'Anioł', 'Annasz', 'Antoni', 'Antonin', 'Antonius',
         'Anzelm', 'Apolinary', 'Apollo', 'Apoloniusz', 'Ariel', 'Arkadiusz', 'Arkady', 'Arnold', 'Artur', 'August',
         'Augustyn', 'Aurelian', 'Baldwin', 'Baltazar', 'Barabasz', 'Barnaba', 'Barnim', 'Bartłomiej', 'Bartosz',
         'Bazyli', 'Beat', 'Benedykt', 'Beniamin', 'Benon', 'Bernard', 'Bert', 'Błażej', 'Bodosław', 'Bogdał', 'Bogdan',
         'Boguchwał', 'Bogumił', 'Bogumir', 'Bogusław', 'Bogusz', 'Bolebor', 'Bolelut', 'Bolesław', 'Bonawentura',
         'Bonifacy', 'Borys', 'Borysław', 'Borzywoj', 'Bożan', 'Bożidar', 'Bożydar', 'Bożimir', 'Bromir', 'Bronisław',
         'Bruno', 'Brunon', 'Budzisław', 'Cecyl', 'Cecylian', 'Celestyn', 'Cezar', 'Cezary', 'Chociemir', 'Chrystian',
         'Chwalibóg', 'Chwalimir', 'Chwalisław', 'Cichosław', 'Ciechosław', 'Cyprian', 'Cyryl', 'Czesław', 'Dacjusz',
         'Dajmir', 'Dal', 'Dalbor', 'Dalgur', 'Damazy', 'Damian', 'Daniel', 'Danisław', 'Danko', 'Dargomir', 'Dargosław',
         'Dariusz', 'Darwit', 'Dawid', 'Denis', 'Derwit', 'Dionizy', 'Dobiesław', 'Dobrogost', 'Dobrosław', 'Domasław',
         'Dominik', 'Donald', 'Donat', 'Dorian', 'Duszan', 'Dymitr', 'Dyter', 'Dzwonimierz', 'Dżamil', 'Dżan', 'Dżem',
         'Dżemil', 'Edgar', 'Edmund', 'Edward', 'Edwin', 'Efraim', 'Efrem', 'Eliasz', 'Eligiusz', 'Eliot', 'Emanuel',
         'Emil', 'Emir', 'Erazm', 'Ernest', 'Erwin', 'Eugeniusz', 'Eryk', 'Ewald', 'Ewaryst', 'Ezaw', 'Ezechiel',
         'Fabian', 'Famian', 'Farid', 'Faris', 'Faustyn', 'Felicjan', 'Feliks', 'Ferdynand', 'Filip', 'Florentyn',
         'Florian', 'Fortunat', 'Franciszek', 'Fryc', 'Fryderyk', 'Gabriel', 'Gaj', 'Gardomir', 'Gaweł', 'Gerard',
         'Gerwazy', 'Gilbert', 'Ginter', 'Gniewomir', 'Gniewosz', 'Godehard', 'Godfryg', 'Godfryd', 'Godzisław',
         'Gościsław', 'Gotard', 'Gotszalk', 'Gracjan', 'Grodzisław', 'Grzegorz', 'Grzymisław', 'Gualfard', 'Gustaw',
         'Gwalbert', 'Gwido', 'Gwidon', 'Hadrian', 'Hasan', 'Hektor', 'Heliodor', 'Henryk', 'Herakles', 'Herakliusz',
         'Herbert', 'Herman', 'Hermes', 'Hiacynt', 'Hieronim', 'Hilary', 'Hipolit', 'Honorat', 'Horacy', 'Hubert',
         'Hugo', 'Hugon', 'Husajn', 'Idzi', 'Ignacy', 'Igor', 'Ildefons', 'Inocenty', 'Ireneusz', 'Iwan', 'Iwo', 'Iwon',
         'Izajasz', 'Izydor', 'Jacek', 'Jacenty', 'Jakub', 'Jan', 'January', 'Janusz', 'Jarad', 'Jaromir', 'Jaropełk',
         'Jarosław', 'Jarowit', 'Jeremiasz', 'Jerzy', 'Jędrzej', 'Joachim', 'Jona', 'Jonasz', 'Jonatan', 'Jozafat',
         'Józef', 'Józefat', 'Julian', 'Juliusz', 'Jur', 'Juri', 'Justyn', 'Justynian', 'Jasuf', 'Kacper', 'Kajetan',
         'Kajfasz', 'Kajusz', 'Kamil', 'Kanimir', 'Karol', 'Kasjusz', 'Kasper', 'Kastor', 'Kazimierz', 'Kemal',
         'Kilian', 'Klaudiusz', 'Klemens', 'Kochan', 'Konrad', 'Konradyn', 'Konstancjusz', 'Konstanty', 'Konstantyn',
         'Kordian', 'Kornel', 'Korneli', 'Korneliusz', 'Kosma', 'Kryspin', 'Krystian', 'Krystyn', 'Krzesimir',
         'Krzesisław', 'Krzysztof', 'Ksawery', 'Kwiatosław', 'Kwietosław', 'Lambert', 'Laurencjusz', 'Lech',
         'Lechosław', 'Lenart', 'Leo', 'Leon', 'Leokadiusz', 'Leonard', 'Leopold', 'Lesław', 'Leszek', 'Lew', 'Longin',
         'Lubisław', 'Lubogost', 'Lubomił', 'Lubomir', 'Luborad', 'Lubosław', 'Lucjan', 'Ludmił', 'Ludomił', 'Ludolf',
         'Ludomir', 'Ludowit', 'Ludwik', 'Ładysław', 'Łazarz', 'Łucjan', 'Łukasz', 'Machut', 'Maciej', 'Magnus',
         'Makary', 'Makryn', 'Maksymilian', 'Maksymin', 'Malachiasz', 'Mamert', 'Manfred', 'Manuel', 'Marcel',
         'Marceli', 'Marcin', 'Marcjan', 'Marek', 'Marian', 'Marin', 'Mariusz', 'Maryn', 'Mateusz', 'Maurycjusz',
         'Maurycy', 'Maurycjusz', 'Medard', 'Melchior', 'Metody', 'Michał', 'Mieszko', 'Mieczysław', 'Mikołaj', 'Milan',
         'Miłobąd', 'Miłogost', 'Miłomir', 'Miłorad', 'Miłosław', 'Miłosz', 'Miłowan', 'Miłowit', 'Mirod', 'Miroład',
         'Miron', 'Mirosław', 'Mirosz', 'Modest', 'Mojmierz', 'Mojmir', 'Mojżesz', 'Mściwoj', 'Murat', 'Myślimir',
         'Napoleon', 'Narcyz', 'Nasif', 'Natan', 'Natanael', 'Nataniel', 'Nestor', 'Nicefor', 'Niecisław', 'Nikodem',
         'Norbert', 'Norman', 'Odo', 'Odon', 'Oktawian', 'Oktawiusz', 'Olaf', 'Oleg', 'Olgierd', 'Omar', 'Onufry',
         'Oskar', 'Orian', 'Otniel', 'Oswald', 'Otokar', 'Otto', 'Otton', 'Owidiusz', 'Ozeasz', 'Pabian', 'Pachomiusz',
         'Pafnucy', 'Pakosław', 'Pankracy', 'Paskal', 'Patrycjusz', 'Patryk', 'Paweł', 'Pelagiusz', 'Petroniusz',
         'Piotr', 'Placyd', 'Polikarp', 'Prokop', 'Prot', 'Protazy', 'Przemysł', 'Przemysław', 'Przedpełk',
         'Przybysław', 'Radogost', 'Radomił', 'Radomir', 'Radosław', 'Radowit', 'Radzimir', 'Rafał', 'Rajmund', 'Rajner',
         'Randoald', 'Remigiusz', 'Renat', 'Richariusz', 'Robert', 'Roch', 'Roderyk', 'Roland', 'Roman', 'Romuald',
         'Ronald', 'Rosłan', 'Rudolf', 'Rufus', 'Ryszard', 'Salomon', 'Samir', 'Sambor', 'Samson', 'Samuel', 'Sebastian',
         'Serafin', 'Sergiusz', 'Serwacy', 'Seweryn', 'Sędomir', 'Sędzisław', 'Siemowit', 'Skałosz', 'Sław', 'Sławek',
         'Sławomierz', 'Sławomir', 'Sobiesław', 'Sofroniusz', 'Stanisław', 'Starwit', 'Stefan', 'Stoigniew', 'Stoisław',
         'Stojan', 'Strzeżymir', 'Subisław', 'Sulibor', 'Sulisław', 'Sydoniusz', 'Sykstus', 'Sylwan', 'Sylwester',
         'Sylwiusz', 'Symeon', 'Symplicjusz', 'Syriusz', 'Szczepan', 'Szymon', 'Świętibor', 'Świętomir', 'Świętopełk',
         'Świętosław', 'Tadeusz', 'Tarik', 'Telesfor', 'Teobald', 'Teodor', 'Teodozjusz', 'Teofil', 'Tęgomir',
         'Tobiasz', 'Tomasz', 'Tomisław', 'Tristan', 'Tulimir', 'Tulimierz', 'Tyberiusz', 'Tymon', 'Tymoteusz', 'Tytus',
         'Urban', 'Ursyn', 'Wacław', 'Wahid', 'Waldemar', 'Walenty', 'Walentyn', 'Walerian', 'Walery', 'Walter',
         'Wandelin', 'Waryn', 'Wawrzyniec', 'Więcesław', 'Wenancjusz', 'Wespazjan', 'Wielisław', 'Wiesław', 'Wiktor',
         'Wilhelm', 'Wincenty', 'Wirgiliusz', 'Wirginiusz', 'Wisław', 'Wit', 'Witold', 'Witołd', 'Witosław', 'Władysław',
         'Włodzimierz', 'Włodzisław', 'Wojciech', 'Wolimir', 'Wojsław', 'Wrocisław', 'Wszebor', 'Zachariasz', 'Zbigniew',
         'Zdzisław', 'Zenobiusz', 'Zefiryn', 'Zenon', 'Ziemowit', 'Zwinisław', 'Zygbert', 'Zygfryd', 'Zygmunt', 'Żarek',
         'Żarko', 'Żelisław', 'Żytomir']

def genUsrGroups(countL, countR, L, R):
    count = countL + countR
    tempNames = []
    for i in range(0, int(count/len(names)) + 1):
        for name in names:
            tempNames.append(name + str(i))

    random.shuffle(tempNames)

    for i in range(0, countL):
        L.append(tempNames.pop())

    for i in range(0, countR):
        R.append(tempNames.pop())

def writeComm(numOfCom, filename, L, R):
    file = open(filename, mode='x')

    for i in range(0, numOfCom):
        source = random.randint(0, len(L)+len(R)-2)
        if source < len(L):
            file.write('#' + L[source] + ": @" + R[random.randint(0, len(R) - 1)] + '\n')
        else:
            file.write('#' + R[source - len(L)] + ": @" + L[random.randint(0, len(L) - 1)] + '\n')


if __name__ == "__main__":
    print ('Number of arguments:', len(sys.argv), 'arguments.')
    print ('Argument List:', str(sys.argv))

    if len(sys.argv) < 4:
        exit(-1)

    # try :
    #     namesFile = open("Asset/names", mode='r', encoding='utf-8')
    #     line = namesFile.readline()
    #     while line:
    #         line = re.sub('\n', '', line)
    #         line = re.sub(' ', '', line)
    #         names.append(line)
    #         line = namesFile.readline()
    # except FileNotFoundError:
    #     print("\"names\" file not found")

    left = []
    right = []

    genUsrGroups(int(sys.argv[1]), int(sys.argv[2]), left, right)
    writeComm(1000, "out.txt", left, right)





