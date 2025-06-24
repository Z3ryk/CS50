//
//  ViewController.swift
//  WeatherApp
//
//  Created by Z3ryk on 04.06.2025.
//

import UIKit

class ViewController: UIViewController {

    private lazy var weatherView = WeatherView(viewController: self)
    
    init() {
        super.init(nibName: nil, bundle: nil)
    }
    
    @available(*, unavailable)
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func loadView() {
        view = weatherView
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // some logic
    }


}
