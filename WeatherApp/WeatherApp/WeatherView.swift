//
//  View.swift

import UIKit

class WeatherView: UIView {
    private weak var viewController: UIViewController?
    private let cityLabel = UILabel()
    private let temperatureLabel = UILabel()
    private let statusWeatherLabel = UILabel()
    private let buttonSearch = UIButton(type: .system)
    private let windSpeedLabel = UILabel()
    private let backgroundImageView = UIImageView()
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        setupView()
        setupUI()
        addSubviews()
        setupConstraints()
    }
    
    init(viewController: UIViewController) {
        self.viewController = viewController
        super.init(frame: .zero)
        setupView()
        setupUI()
        addSubviews()
        setupConstraints()
    }
    
    @available(*, unavailable)
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    private func setupView() {
        backgroundColor = .systemBackground
        
    }
    
    private func setupUI() {
        cityLabel.text = "City"
        cityLabel.textAlignment = .center
        cityLabel.font = .systemFont(ofSize: 50)
        cityLabel.textColor = .white
        
        temperatureLabel.text = "-°C"
        temperatureLabel.textAlignment = .center
        temperatureLabel.font = .systemFont(ofSize: 40)
        temperatureLabel.textColor = .white
        
        statusWeatherLabel.text = "status"
        statusWeatherLabel.textAlignment = .center
        statusWeatherLabel.font = .systemFont(ofSize: 20)
        statusWeatherLabel.textColor = .white
        
        windSpeedLabel.text = "wind speed"
        windSpeedLabel.textAlignment = .center
        windSpeedLabel.font = .systemFont(ofSize: 20)
        windSpeedLabel.textColor = .white
        
        buttonSearch.setImage(UIImage(systemName: "plus"), for: .normal)
        buttonSearch.tintColor = .white
        buttonSearch.backgroundColor = .systemBlue
        buttonSearch.layer.cornerRadius = 21
        buttonSearch.addTarget(self, action: #selector(searchButtonTapped), for: .touchUpInside)
        
        backgroundImageView.image = UIImage(named: "Clouds")
        
    }
    
    private func setupConstraints() {
        [cityLabel, temperatureLabel, statusWeatherLabel, windSpeedLabel, buttonSearch, backgroundImageView].forEach {
            $0.translatesAutoresizingMaskIntoConstraints = false
        }
        
        NSLayoutConstraint.activate([
            
            cityLabel.topAnchor.constraint(equalTo: safeAreaLayoutGuide.topAnchor, constant: 100),
            cityLabel.leadingAnchor.constraint(equalTo: leadingAnchor, constant: 20),
            
            temperatureLabel.topAnchor.constraint(equalTo: cityLabel.bottomAnchor, constant: 20),
            temperatureLabel.leadingAnchor.constraint(equalTo: leadingAnchor, constant: 40),
            
            statusWeatherLabel.topAnchor.constraint(equalTo: temperatureLabel.bottomAnchor, constant: 20),
            statusWeatherLabel.leadingAnchor.constraint(equalTo: leadingAnchor, constant: 40),
            
            windSpeedLabel.topAnchor.constraint(equalTo: statusWeatherLabel.bottomAnchor, constant: 20),
            windSpeedLabel.leadingAnchor.constraint(equalTo: leadingAnchor, constant: 40),
            
            buttonSearch.widthAnchor.constraint(equalToConstant: 40),
            buttonSearch.heightAnchor.constraint(equalToConstant: 40),
            buttonSearch.trailingAnchor.constraint(equalTo: trailingAnchor, constant: -30),
            buttonSearch.topAnchor.constraint(equalTo: safeAreaLayoutGuide.topAnchor, constant: 30),
            
            backgroundImageView.topAnchor.constraint(equalTo: topAnchor),
            backgroundImageView.leadingAnchor.constraint(equalTo: leadingAnchor),
            backgroundImageView.trailingAnchor.constraint(equalTo: trailingAnchor),
            backgroundImageView.bottomAnchor.constraint(equalTo: bottomAnchor)
        ])
        
    }
    
    
    @objc private func searchButtonTapped() {
        UIView.animate(withDuration: 0.1, animations: {
            self.buttonSearch.transform = CGAffineTransform(scaleX: 0.9, y: 0.9)
        }, completion: { _ in
            UIView.animate(withDuration: 0.1) {
                self.buttonSearch.transform = .identity
            }

            let searchVC = CitySearchViewController()
            searchVC.onCitySelected = { [weak self] location in
                guard let self = self else { return }
                self.cityLabel.text = location.name
                locationData["lat"] = Double(round(location.lat * 100) / 100)
                locationData["lon"] = Double(round(location.lon * 100) / 100)
                locationData["state"] = location.state
                locationData["country"] = location.country
                locationData["nameLocation"] = location.name
                cityWeather()
                self.temperatureLabel.text = "\(WeatherData["temp"] ?? 0)°C"
                self.statusWeatherLabel.text = "\(WeatherData["weatherStatus"] ?? "")"
                self.windSpeedLabel.text = "wind speed: \(WeatherData["windSpeed"] ?? 0) m/s"
                if statusWeatherLabel.text == "Rain" {
                    backgroundImageView.image = UIImage(named: "Dark Clouds")
                } else {
                    backgroundImageView.image = UIImage(named: "Clouds")
                }
            }

            let nav = UINavigationController(rootViewController: searchVC)
            self.viewController?.present(nav, animated: true)
        })
    }
    
    private func addSubviews () {
        addSubview(backgroundImageView)
        addSubview(cityLabel)
        addSubview(temperatureLabel)
        addSubview(statusWeatherLabel)
        addSubview(buttonSearch)
        addSubview(windSpeedLabel)
    }
    
}
#Preview(){
    WeatherView()
}
