//
//  SearchCityViewController.swift
//  WeatherApp
//
//  Created by Z3ryk on 22.06.2025.
//


import UIKit

class CitySearchViewController: UITableViewController, UISearchResultsUpdating {

    private var filteredCities: [Location] = []
    private let searchController = UISearchController(searchResultsController: nil)
    var onCitySelected: ((Location) -> Void)?

    override func viewDidLoad() {
        super.viewDidLoad()
        title = "Выбор города"
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "cell")

        searchController.searchResultsUpdater = self
        searchController.obscuresBackgroundDuringPresentation = false
        searchController.searchBar.placeholder = "Введите название города"
        navigationItem.searchController = searchController
        definesPresentationContext = true
    }

    func updateSearchResults(for searchController: UISearchController) {
        guard let searchText = searchController.searchBar.text, !searchText.isEmpty else {
            filteredCities = []
            tableView.reloadData()
            return
        }

        searchCities(query: searchText)
    }

    private func searchCities(query: String) {
        let apiKey = "f6f5561ca655cbfb4e43d58a28e47aae"
        let urlString = "https://api.openweathermap.org/geo/1.0/direct?q=\(query)&limit=5&appid=\(apiKey)"
        guard let url = URL(string: urlString) else { return }

        URLSession.shared.dataTask(with: url) { data, _, _ in
            guard let data = data,
                  let cities = try? JSONDecoder().decode([Location].self, from: data) else { return }

            DispatchQueue.main.async {
                self.filteredCities = cities
                self.tableView.reloadData()
            }
        }.resume()
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return filteredCities.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let city = filteredCities[indexPath.row]
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath)
        cell.textLabel?.text = "\(city.name ?? "") (\(city.country ?? ""))"
        return cell
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let selectedCity = filteredCities[indexPath.row]
        onCitySelected?(selectedCity)
        navigationController?.dismiss(animated: true)
    }
}
