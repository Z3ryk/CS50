//
//  NetworkAPI.swift
//  WeatherApp
//
//  Created by Z3ryk on 15.06.2025.
import UIKit
import Foundation

var filteredCities: [Location] = []

struct Location: Codable {
    let lat: Double
    let lon: Double
    let state: String?
    let country: String?
    let name: String?
}

var locationData = ["lon": 0, "lat": 0, "state": "0", "country": "0", "nameLocation": "0"] as [String : Any]

private let apiKey = "f6f5561ca655cbfb4e43d58a28e47aae"

enum CityAPI {
    static func searchCities(cityName: String, completion: @escaping ([Location]) -> Void) {
        let urlString = "https://api.openweathermap.org/geo/1.0/direct?q=\(cityName)&limit=5&appid=\(apiKey)"
        guard let url = URL(string: urlString) else {
            completion([])
            return
        }

        URLSession.shared.dataTask(with: url) { data, _, _ in
            guard let data = data,
                  let cities = try? JSONDecoder().decode([Location].self, from: data) else {
                completion([])
                return
            }
            completion(cities)
        }.resume()
    }
}


// MARK: Weather

struct WeatherResponse: Codable {
    let weather: [Weather]
    let base: String
    let main: Main
    let visibility: Int
    let wind: Wind
    let name: String
}

struct Weather: Codable {
    let main: String
}

struct Main: Codable {
    let temp: Double
    let feels_like: Double
    let temp_min: Double
    let temp_max: Double
}

struct Wind: Codable {
    let speed: Double
}

var WeatherData = ["temp": 0, "feelsLike": 0, "windSpeed": 0, "weatherStatus": "Clear"] as [String : Any]

func cityWeather() {
    
    let weatherUrlString = "https://api.openweathermap.org/data/2.5/weather?lat=\(locationData["lat"] ?? 0)&lon=\(locationData["lon"] ?? 0)&appid=\(apiKey)&units=metric"
    
    guard let weatherUrl = URL(string: weatherUrlString) else {
        print("Invalid URL")
        exit(1)
    }
    
    let semaphore2 = DispatchSemaphore(value: 0)
    
    let task2 = URLSession.shared.dataTask(with: weatherUrl) { data, response, error in
        if let error = error {
            print("Error: \(error)")
            return
        }
        
        guard let httpResponse = response as? HTTPURLResponse else {
            print("No HTTP response")
            return
        }
        
        guard httpResponse.statusCode == 200 else {
            print("HTTP status code: \(httpResponse.statusCode)")
            return
        }
        
        guard let data = data else {
            print("No data returned")
            return
        }
        
        do {
            let weather = try JSONDecoder().decode(WeatherResponse.self, from: data)
            
            print("Температура: \(weather.main.temp)")
            print("Ощущается как: \(weather.main.feels_like)")
            print("Минимальная температура: \(weather.main.temp_min)")
            print("Максимальная температура: \(weather.main.temp_max)")
            print("Ветер: \(weather.wind.speed)")
            print("Статус погоды: \(weather.weather.first?.main ?? "неизвестно")")
            print("-----")
            
            WeatherData["temp"] = Int(weather.main.temp)
            WeatherData["feelsLike"] = Int(weather.main.feels_like)
            WeatherData["windSpeed"] = weather.wind.speed
            WeatherData["weatherStatus"] = weather.weather.first?.main ?? "неизвестно"
            
            print(WeatherData)
            
        } catch {
            print("Ошибка парсинга: \(error)")
        }
        semaphore2.signal()
    }
    task2.resume()
    semaphore2.wait()
}
