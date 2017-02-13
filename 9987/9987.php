<?php
namespace App\Http\Controllers;
use App\Http\Controllers\Controller;

class TestController extends Controller{
    public function crawl(){
        $url = 'http://web.archive.org/web/20140301191716/http://pokemondb.net/pokedex/national';
        $html = file_get_contents($url);

        $fp = fopen("result.txt", "a");
        $end = false;

        $html = substr($html, strpos($html, 'infocard-tall-list') + 1);

        while ($end === false){
            $txt = '';

            $html = substr($html, strpos($html, '<small>#') + 8);
            $num = (int)substr($html, 0, strpos($html, '</small>'));

            $html = substr($html, strpos($html, '<a'));
            $html = substr($html, strpos($html, '>') + 1);
            $name = substr($html, 0, strpos($html, '</a>'));

            $type = '';

            while (true){
                $html = substr($html, strpos($html, '<a'));
                $html = substr($html, strpos($html, '>') + 1);
                $type .= substr($html, 0, strpos($html, '</a>'));

                $temp = strpos($html, 'infocard-tall');

                if ($temp !== false){
                    if (strpos($html, '<a') > $temp){
                        break;
                    }
                    else{
                        $type .= ' ';
                    }
                }
                else{
                    if (strpos($html, '<a') > strpos($html, 'ad-responsive')){
                        $end = true;
                        break;
                    }
                    else{
                        $type .= ' ';
                    }
                }
            }

            $txt .= "strcpy(arr[".$num."]->name, \"".$name."\");\r\n";
            $txt .= "strcpy(arr[".$num."]->type, \"".$type."\");\r\n";

            fwrite($fp, $txt);
        }

        fclose($fp);
    }
}
